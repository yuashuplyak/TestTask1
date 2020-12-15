#pragma once
#include <memory>
#include "IFileReader.h"
#include <stdio.h>
#include <filesystem>
#include "String/String.h"

namespace test
{

class FileReader : public IFileReader
{
public:
    FileReader();
    virtual ~FileReader();

    virtual bool initialize(const std::string& fileName) override final;
    
    virtual std::unique_ptr<String> read() override;

protected:
    FILE *file() const;

private:
    FILE* m_file;
    decltype(std::filesystem::file_size("")) m_fileSize{};
    std::unique_ptr<char[]> buf;
    std::size_t currentSizeBuf{};
};

}
