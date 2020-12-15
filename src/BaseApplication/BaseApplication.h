#pragma once

#include "Options.h"
#include <string>
#include <unordered_map>

namespace test
{
    
class BaseApplication
{
public:
    BaseApplication(int argc, char *argv[]);
    
    virtual ~BaseApplication();
    
    BaseApplication(const BaseApplication& ) = delete;
    BaseApplication& operator = (const BaseApplication& ) = delete;
    
    BaseApplication(BaseApplication&& ) = delete;
    BaseApplication& operator = (BaseApplication&& ) = delete;
    
    virtual std::string_view getName() final
    {
        return APPLICATION_NAME;
    }

    virtual std::string_view getVersion() final
    {
        return APPLICATION_VERSION;
    }

    virtual int run() final;

protected:
    virtual int work() = 0;

    virtual std::string getParam(const std::string& name) const;

private:
    std::unordered_map<std::string, std::string> m_config;
    bool showVersion{false};
};

    
}
