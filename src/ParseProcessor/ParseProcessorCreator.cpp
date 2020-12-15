#include "ParseProcessorCreator.h"
#include "Parser/ParserCreator.h"
#include "ParseProcessor.h"

using namespace test;

std::unique_ptr<IParseProcessor> ParseProcessorCreator::create()
{
    auto parseProsessor = std::make_unique<ParseProcessor>();
    parseProsessor->initialize(ParserCreator::create());

    return parseProsessor;
}
