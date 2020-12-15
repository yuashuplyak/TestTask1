#include "TestApplication/TestApplication.h"

int main(int argc, char *argv[])
{
    using test::TestApplication;
    TestApplication app(argc, argv);
    auto result = app.run();
    return result;
}
