#include "Report.h"
#include <iostream>
#include "Parser/ParserResult.h"

using namespace test;

Report::Report()
{

}

Report::~Report()
{

}

void Report::show()
{

}


void Report::initialize(std::unique_ptr<ParserResult>&& results)
{
    std::cout << "Direction -1 : " << results->negativeDirectionDistance <<std::endl;
    std::cout << "Direction 1 : " << results->positivDirectionDistance <<std::endl;
}
