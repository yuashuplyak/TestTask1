#include "FileReaderCreator.h"
#include "FileReader.h"

using namespace test;

std::unique_ptr<IFileReader> FileReaderCreator::create()
{
    return std::make_unique<FileReader>();
}
