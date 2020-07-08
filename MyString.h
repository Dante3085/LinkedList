
#pragma once

#include <iostream>

class MyString
{
public:
    MyString() = default;
    MyString(char const *string)
    {
        // std::cout << "Constructed!" << std::endl;

        m_size = strlen(string);
        m_data = new char[m_size];

        // Copies count bytes from the object pointed to by src to the object pointed to by dest.
        // Both objects are reinterpreted as arrays of unsigned char.
        //     dest  , src   , count
        memcpy(m_data, string, m_size);
    }

    MyString(MyString const &other)
    {
        // std::cout << "Copied!" << std::endl;

        m_size = other.m_size;
        m_data = new char[m_size];
        memcpy(m_data, other.m_data, m_size);
    }

    MyString(MyString &&other) noexcept
    {
        // std::cout << "Moved" << std::endl;

        m_size = other.m_size;
        m_data = other.m_data;

        other.m_size = 0;
        other.m_data = nullptr;
    }

    ~MyString()
    {
        // std::cout << "Deleted!" << std::endl;

        delete[] m_data;
    }

    friend std::ostream &operator<<(std::ostream &ostream, MyString const &s);

private:
    char *m_data;
    uint32_t m_size;
};

std::ostream &operator<<(std::ostream &ostream, MyString const &s)
{
    return ostream << s.m_data;
}