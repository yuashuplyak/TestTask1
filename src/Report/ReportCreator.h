#pragma once
#include "IReport.h"
#include <memory>
namespace test
{

class ReportCreator
{
public:
    static std::unique_ptr<IReport> create();
};

}
