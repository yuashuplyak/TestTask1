#pragma once
#include <string>
#include <memory>
#include "String/String.h"
#include "Parser/IParser.h"

namespace test
{
struct ParseResult;

/*!
 * \class IParseProcessor
 * \brief Определяет интерфейс основного расчётного модуля, распределяющего данные между паралельно работающими парсерами
 */
class IParseProcessor
{
public:
    IParseProcessor() = default;
    
    virtual ~IParseProcessor() = default;
    
    IParseProcessor(const IParseProcessor& ) = default;
    IParseProcessor& operator = (const IParseProcessor& ) = default;
    
    IParseProcessor(IParseProcessor&& ) = default;
    IParseProcessor& operator = (IParseProcessor&& ) = default;
    
    /*!
     * \brief Инициализация расчётного модуля
     * \param parser - указатель на интерфейс объекта
     * \return успешность операции
     */
    virtual bool initialize(std::unique_ptr<IParser>&& parser) = 0;

    /*!
     * \brief Выполнение парсинга считанных данных
     * \param str - передаваемая строка
     */
    virtual void process(std::unique_ptr<String>&& str) = 0;


    /*!
     * \brief Получение итоговых результатов
     * \return Результаты
     */
    virtual std::unique_ptr<ParserResult> getResults() const = 0;

};

}
