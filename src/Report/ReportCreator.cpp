#include "ReportCreator.h"
#include "Report.h"

using namespace test;

std::unique_ptr<IReport> ReportCreator::create()
{
    return std::make_unique<Report>();
}
