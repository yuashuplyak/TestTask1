#pragma once

#include "IFileReader.h"

namespace test
{

class FileReaderCreator
{
public:
    static std::unique_ptr<IFileReader> create();
     
};

}
