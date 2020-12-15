#pragma once
#include "IReport.h"

namespace test
{
class Report : public IReport
{
public:
    Report();
    virtual ~Report();

    virtual void show() override;

    virtual void initialize(const std::unique_ptr<ParseResult>&) override;
};
}
