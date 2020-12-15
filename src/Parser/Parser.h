#pragma once
#include <memory>
#include "IParser.h"

namespace test
{

class Parser : public IParser
{
public:
    Parser();
    virtual ~Parser();

    //virtual std::unique_ptr<ParserResult> parse(std::unique_ptr<std::pair<const char*, std::size_t>>&& ) override;
    virtual std::unique_ptr<ParserResult> parse(PtrString&& ) override;
};

}
