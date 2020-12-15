#include "TestApplication.h"
#include "FileReader/FileReaderCreator.h"
#include "ParseProcessor/ParseProcessorCreator.h"
#include "Report/ReportCreator.h"
#include <iostream>

#include <chrono>

using namespace test;

TestApplication::TestApplication(int argc, char *argv[]) : BaseApplication(argc, argv)
{

}

TestApplication::~TestApplication()
{

}

int TestApplication::work()
{
    auto fileReader = FileReaderCreator::create();
    std::unique_ptr<IParseProcessor> parseProcessor = ParseProcessorCreator::create();
    auto report = ReportCreator::create();

    auto fileName = getParam("file");
    fileReader->initialize(fileName);

    auto time = std::chrono::system_clock::now();

    while (true)
    {
        auto&& str = fileReader->read();
        if (nullptr==str)
            break;

        parseProcessor->process(std::move(str));
    }

    auto results = parseProcessor->getResults();
    auto workTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - time).count();

    std::cout << "Work time: "<< workTime << " millisecond" << std::endl;

    report->initialize(std::move(results));
    report->show();

    return 0;
}
