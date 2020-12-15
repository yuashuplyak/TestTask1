#include "BaseApplication.h"
#include <iostream>

using namespace test;

BaseApplication::BaseApplication(int argc, char *argv[])
{
    if (argc>1)
    {
        std::string paramName;
        for (int i{1}; i<argc; ++i)
        {
            if('-'==*argv[i])
            {
                std::string str = argv[i]+1;
                if ("-version")
                {
                    showVersion = true;
                    paramName.clear();
                }
                else
                   paramName = std::move(str);
            }
            else if(!paramName.empty())
            {
                m_config[paramName] = argv[i];
                paramName.clear();
            }
        }
    }
}

BaseApplication::~BaseApplication()
{

}

int BaseApplication::run()
{
    if (showVersion)
    {
        std::cout << APPLICATION_NAME << " version " << APPLICATION_VERSION << std::endl;
        return 0;
    }

    return work();
}

std::string BaseApplication::getParam(const std::string& name) const
{
    auto it = m_config.find(name);
    if (m_config.end()==it)
        return "";

    return it->second;
}
