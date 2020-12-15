#pragma once

#include<memory>
#include "IParseProcessor.h"

namespace test
{

/*!
 * \class ParseProcessorCreator
 * \brief Создаёт основной расчётный модуль для парсинга строк
 */
class ParseProcessorCreator
{
public:

    /*!
     * \brief Создаёт основной расчётный модуль
     * \return указатель на интерфейс основного расчётного модуля
     */
    static std::unique_ptr<IParseProcessor> create();
};

}

