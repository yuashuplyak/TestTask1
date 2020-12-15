#include "ParserCreator.h"
#include "Parser.h"
using namespace test;

std::unique_ptr<IParser> ParserCreator::create()
{
    return std::make_unique<Parser>();
}
