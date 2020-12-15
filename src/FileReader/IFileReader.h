#pragma once
#include <string>
#include <memory>
#include "String/String.h"

namespace test
{
/*!
 * \class IFileReader
 * \brief Определяет интерфейс чтения файла
 */
class IFileReader
{
public:
    IFileReader() = default;
    virtual ~IFileReader() = default;

    /*!
     * \brief Инициализация класса
     * \param fileName - имя файла
     * \return
     */
    virtual bool initialize(const std::string& fileName) = 0;

    /*!
     * \brief Чтение из файла
     * \return объект строки
     */
    virtual std::unique_ptr<String> read() = 0;
};

}
