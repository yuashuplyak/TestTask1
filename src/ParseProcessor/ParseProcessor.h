#pragma once
#include "IParseProcessor.h"
#include <mutex>
#include <vector>
#include <thread>
#include "ThreadSafeQueue/ThreadSafeQueue.h"
#include "Parser/IParser.h"

namespace test
{

class ParseProcessor : public IParseProcessor
{
public:
    ParseProcessor();
    virtual ~ParseProcessor();
    
    ParseProcessor(const ParseProcessor& ) = delete;
    ParseProcessor& operator = (const ParseProcessor& ) = delete;
    
    ParseProcessor(ParseProcessor&& ) = default;
    ParseProcessor& operator = (ParseProcessor&& ) = default;
    
    virtual bool initialize(std::unique_ptr<IParser>&& parser) override;

    virtual void process(std::unique_ptr<String>&& str) override;

    virtual const std::unique_ptr<ParseResult>& getResults() const override;

private:
    std::unique_ptr<ParseResult> m_result;
    std::vector<ParserResult> m_results;
    std::vector<std::unique_ptr<ThreadSafeQueue<PtrString>>> m_memQueue;
    mutable std::vector<std::thread> m_thread;
    std::vector<std::unique_ptr<String>> m_strings;
    std::unique_ptr<IParser> m_parser;

};

}
