#pragma once
#include "BaseApplication/BaseApplication.h"

namespace test
{
    
class TestApplication : public BaseApplication
{
public:
    TestApplication(int argc, char *argv[]);
    
    virtual ~TestApplication();
    
    TestApplication(const TestApplication& ) = delete;
    TestApplication& operator = (const TestApplication& ) = delete;
    
    TestApplication(TestApplication&& ) = delete;
    TestApplication& operator = (TestApplication&& ) = delete;
    
    virtual int work() override;
};

    
}
