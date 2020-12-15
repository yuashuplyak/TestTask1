#pragma once
#include <memory>

namespace test
{
template <typename T>
class StringBase
{
public:
    StringBase() =default;
    StringBase(std::size_t size, T&& data) : m_size{size}, m_data{std::move(data)}
    {}

    StringBase(std::size_t size, const T& data) : m_size{size}, m_data{data}
    {}

    ~StringBase() =default;

    StringBase(const StringBase& ) = delete;
    StringBase& operator = (const StringBase& ) = delete;

    StringBase(StringBase&& ) = default;
    StringBase& operator = (StringBase&& ) = default;

    const char* data() const;

    std::size_t size() const;

private:
    std::size_t m_size{};
    T m_data{};
};

template <typename T>
inline const char* StringBase<T>::data() const
{
    return m_data;
}

template <>
inline const char* StringBase<std::unique_ptr<char[]>>::data() const
{
    return m_data.get();
}

template <typename T>
inline std::size_t StringBase<T>::size() const
{
    return m_size;
}

using String = StringBase<std::unique_ptr<char[]>>;
using PtrString = StringBase<const char*>;

}
