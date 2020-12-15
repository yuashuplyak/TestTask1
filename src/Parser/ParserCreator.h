#pragma once
#include "IParser.h"

namespace test
{

class ParserCreator
{
public:
    static std::unique_ptr<IParser> create();
};

}
