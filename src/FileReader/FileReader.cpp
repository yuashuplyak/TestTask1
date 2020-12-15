#include "FileReader.h"
#include <iostream>
#include <String/String.h>
#include <cstring>

using namespace test;

FileReader::FileReader()
{

}

FileReader::~FileReader()
{
    if (nullptr != m_file)
        fclose(m_file);
}

bool FileReader::initialize(const std::string &fileName)
{
    m_fileSize = std::filesystem::file_size(fileName);
    m_file = fopen(fileName.c_str(), "r");
    return (m_file !=nullptr);
}

std::unique_ptr<String> FileReader::read()
{
    constexpr std::size_t sizeBuf{12*1024};
    if (nullptr == buf)
    {
        buf = std::make_unique<char[]>(sizeBuf);
    }
    auto beginPtr = buf.get() + currentSizeBuf;

    auto sizeRead = fread(beginPtr, 1, sizeBuf-currentSizeBuf, m_file);
    if(!sizeRead)
        return nullptr;

    sizeRead += currentSizeBuf;

    char* end = buf.get() + sizeRead - 1;

    std::size_t size{};
    while (*end!='{' && *end!='}' && size!=sizeRead)
    {
        --end;
        ++size;
    }

    auto newBuf = std::make_unique<char[]>(sizeBuf);
    if ('{'==*end)
    {
        ++size;
        memcpy(newBuf.get(), end, size);
        currentSizeBuf = size;
    }
    else
    {
        beginPtr = newBuf.get();
        currentSizeBuf = 0;
    }

    auto result = std::make_unique<String>(sizeRead-currentSizeBuf, std::move(buf));
    buf = std::move(newBuf);

    return result;
}

FILE *FileReader::file() const
{
    return m_file;
}
