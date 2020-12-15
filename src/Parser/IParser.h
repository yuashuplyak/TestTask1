#pragma once
#include <memory>
#include "Parser/ParserResult.h"
#include <String/String.h>

namespace test
{

struct ParserResult;

/*!
 * \class IParser
 * \brief Определяет интерфейс модуля выполняющего парсинг строки
 * \details На вход должна подаётся строка, состоящая из указателя на данные и размера строки
 * строка должна состоять из данных, ограниченных замкнутыми скобками {...}{...}
 */
class IParser
{
public:
    IParser() = default;
    virtual ~IParser() = default;
    
    IParser(const IParser& ) = default;
    IParser& operator = (const IParser& ) = default;
    
    IParser(IParser&& ) = default;
    IParser& operator = (IParser&& ) = default;
    
    /*!
     * \brief Выполняется парсин строки
     * \param ptrString - данные для парсинга
     * \return
     */
    virtual std::unique_ptr<ParserResult> parse(PtrString&& ptrString) = 0;

};

}
