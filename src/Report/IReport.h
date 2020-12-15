#pragma once
#include <memory>

namespace test
{
struct ParseResult;

class IReport
{
public:
    IReport() = default;
    virtual ~IReport() = default;
    virtual void initialize(const std::unique_ptr<ParseResult>&) = 0;
    virtual void show() = 0;
};

}
