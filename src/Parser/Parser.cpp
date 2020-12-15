#include "Parser.h"
#include "ParserResult.h"
#include <cstring>

using namespace test;

Parser::Parser()
{

}

Parser::~Parser()
{

}

std::unique_ptr<ParserResult> Parser::parse(PtrString&& str)
{
    int direction;
    float speed;
    float time;
    std::size_t count{};

    double negativeDirectionDistance{};
    double positivDirectionDistance{};

    auto pstr = str.data();
    while(true)
    {
        int readingByteCount{};

        auto newPos = strstr(pstr, "direction");
        auto dist = newPos - pstr;
        pstr = newPos;
        sscanf(pstr, "direction\":\"%d\",\"speed\":\"%f\",\"time\":%f}%n", &direction, &speed, &time, &readingByteCount);

        if(direction<0)
            negativeDirectionDistance +=double(speed)*time;
        else
            positivDirectionDistance+=double(speed)*time;

        count += readingByteCount + dist;
        if (count>=str.size() || 0 == readingByteCount)
        {
            break;
        }
        pstr += readingByteCount ;
    }

    return std::make_unique<ParserResult>(negativeDirectionDistance, positivDirectionDistance);
}
