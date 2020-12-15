#pragma once
#include <memory>

namespace test
{

struct ParserResult;

class IReport
{
public:
    IReport() = default;
    virtual ~IReport() = default;
    virtual void initialize(std::unique_ptr<ParserResult>&&) = 0;
    virtual void show() = 0;
};

}
