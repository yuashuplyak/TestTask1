#include "ParseProcessor.h"
#include "ParseResult.h"
#include <iostream>
#include <cstring>

using namespace test;
static constexpr std::size_t nThread{8};

ParseProcessor::ParseProcessor()
{
    m_thread.reserve(nThread);
    for (std::size_t i{}; i<nThread; ++i)
    {
        m_memQueue.push_back(std::make_unique<ThreadSafeQueue<PtrString>>());
        m_results.emplace_back();
        m_thread.emplace_back( [=]()
        {
            while(true)
            {
                auto pstr = m_memQueue[i]->waitPop();
                if(nullptr == pstr.data())
                    break;

                auto result = m_parser->parse(std::move(pstr));
                if (nullptr == result)
                    break;

                m_results[i]+=*result;
            }
        });
    }
}

ParseProcessor::~ParseProcessor()
{
    for (std::size_t i{}; i<nThread; ++i)
        m_memQueue[i]->stop();

    m_memQueue.clear();
}

void ParseProcessor::process(std::unique_ptr<String>&& mem)
{
    static auto correct = [](auto& data, auto& size, auto& end, const auto maxSize)
    {
        end = data + size - 1;

        while (*end!='}' && size<=maxSize)
        {
            ++end;
            if (*end == '{')
                break;
            ++size;
        }

        while (*data!='{' || 0==size)
        {
            ++data;
            --size;
        }
    };

    auto maxSize = mem->size()-1;
    auto sizeBase = maxSize/nThread;
    auto start = mem->data();
    auto size = sizeBase;
    auto end = start;

    for(std::size_t i{}; i<nThread; ++i)
    {
        correct(start, size, end,  maxSize);

        m_memQueue[i]->push(PtrString(size, start));
        start += size;

        if (size>=maxSize)
            break;

        maxSize -= (size + 1);

        if (nThread-i>1)
            size = maxSize/(nThread-i-1);
    }


    m_strings.push_back(std::move(mem));
}


 std::unique_ptr<ParserResult> test::ParseProcessor::getResults() const
{
    ParserResult mainResult;
    for (std::size_t i{}; i<nThread; ++i)
    {
        while(m_memQueue[i]->getSize() > 0)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        m_memQueue[i]->stop();
        m_thread[i].join();

        mainResult+=m_results[i];
    }

    return std::make_unique<ParserResult>(mainResult);
}


bool test::ParseProcessor::initialize(std::unique_ptr<IParser> &&parser)
{
    m_parser = std::move(parser);
    return true;
}
