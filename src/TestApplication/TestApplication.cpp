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
    fileReader->initialize("xxx.txt");

    auto time = std::chrono::system_clock::now();

    int count{};
    while (true)
    {
        auto&& str = fileReader->read();
        if (nullptr==str)
            break;

        parseProcessor->process(std::move(str));
        ++count;
    }

    const auto& results = parseProcessor->getResults();
    auto workTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - time).count();

    std::cout << workTime << " " << count << std::endl;

    return 0;
    report->initialize(results);
    report->show();

    return 0;
}
