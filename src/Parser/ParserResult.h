#pragma once

namespace test
{

struct ParserResult
{
    ParserResult() = default;
    ~ParserResult() = default;

    template<typename T1, typename T2>
    ParserResult(T1 _negativeDirectionDistance, T2 _positivDirectionDistance) = delete;

    ParserResult(double _negativeDirectionDistance, double _positivDirectionDistance)
        : negativeDirectionDistance{_negativeDirectionDistance}
        , positivDirectionDistance{_positivDirectionDistance}
    {}


    double negativeDirectionDistance{};
    double positivDirectionDistance{};

    void operator += (const ParserResult& parserResult)
    {
        negativeDirectionDistance+=parserResult.negativeDirectionDistance;
        positivDirectionDistance+=parserResult.positivDirectionDistance;
    }
};

}
