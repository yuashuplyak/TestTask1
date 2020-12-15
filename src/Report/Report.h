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

    virtual void initialize(std::unique_ptr<ParserResult>&&) override;
};
}
