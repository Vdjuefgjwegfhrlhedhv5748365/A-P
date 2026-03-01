#include "my_string.hpp"
#include <iostream>

// функцияя вычисления строки
size_t str_length(const char *str)
{
    if (str == nullptr)
        return 0;
    size_t len = 0;
    while (str[len] != '\0')
    {
        ++len;
    }
    return len;
}

// функция для копирования строки
void str_copy(char *dest, const char *src)
{
    if (dest == nullptr || src == nullptr)
        return;
    size_t i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
}

MyString::MyString() : m_string(nullptr), m_length(0)
{
    std::cout << "Конструктор по умолчанию. Создана пустая строка" << std::endl;
}

MyString::MyString(const char *string1) : m_string(nullptr), m_length(0)
{
    if (string1 == nullptr)
    {
        std::cout << "Конструктор с параметрами. Получен nullptr, память не выделяется" << std::endl;
        return;
    }

    m_length = str_length(string1); // вычисляем длину исходной строки
    if (m_length > 0)
    {
        m_string = new char[m_length + 1]; //+1 для нуль-терминатора
        std::cout << "Конструктор с параметрам. Выделено " << (m_length + 1) << "байт памяти" << std::endl;
        str_copy(m_string, string1);
    }

    else
    {
        std::cout << "Конструктор с параметром: пустая строка - память не выделяется" << std::endl;
    }
}
MyString::MyString(const MyString &other)
{
    std::cout << "Конструктор копирования MyString" << std::endl;

    if (other.m_string == nullptr)
    {
        m_string = nullptr;
        m_length = 0;
        return;
    }

    m_length = other.m_length;
    m_string = new char[m_length + 1];

    for (size_t i = 0; i < m_length; i++)
    {
        m_string[i] = other.m_string[i];
    }
    m_string[m_length] = '\0';
}

char MyString ::get(int i) const
{
    if (i < 0 || i >= m_length)
    {
        std::cout << "Ошибка: индекс" << i << "вне границ строки" << std::endl;
        return '\0';
    }
    if (m_string == nullptr)
    {
        std::cout << "Ошибка строка пустая" << std::endl;
        return '\0';
    }
    return m_string[i];
}

void MyString ::set(int i, char c)
{
    if (i < 0 || i >= m_length)
    {
        std::cout << "Ошибка: индекс" << i << "вне границ строки" << std::endl;
        return;
    }
    if (m_string == nullptr)
    {
        std::cout << "Ошибка строка пустая" << std::endl;
        return;
    }
    m_string[i] = c;
}

void MyString ::setNewString(const char *str)
{
    if (str == nullptr)
    {
        std::cout << "Ошибка: передан nullptr" << std::endl;
        return;
    }
    int new_length = str_length(str);
    if (new_length == 0)
    {
        if (m_string != nullptr)
        {
            delete[] m_string;
            m_string = nullptr;
        }
        m_length = 0;
        std::cout << "Строка стала пустой" << std::endl;
    }
    if (m_string == nullptr || m_length != new_length)
    {
        if (m_string != nullptr)
            delete[] m_string;
        m_string = new char[new_length + 1];
        m_length = new_length;
        str_copy(m_string, str);
    }
    std::cout << "Произведена замена текущего содержимого на новое" << std::endl;
}

void MyString ::print() const
{
    if (m_string == nullptr || m_length == 0)
    {
        std::cout << "Ошибка: строка пустая" << std::endl;
        return;
    }

    std::cout << m_string << std::endl; // перевод строки в конце
}

void MyString ::readLine()
{
    if (m_string != nullptr)
    {
        delete[] m_string;
        m_string = nullptr;
        m_length = 0;
    }
    std::cout << "Введите строку. Enter - конец строки.";
    int str_capacity = 16;
    m_string = new char[str_capacity];
    m_length = 0;
    char ch;
    while (true)
    {
        ch = std::cin.get();
        if (ch == '\n')
        {
            break;
        }
        if (m_length + 1 >= str_capacity)
        {
            int newStr_capacity = str_capacity * 2;
            char *Temp = new char[newStr_capacity];

            for (int i = 0; i < m_length; i++)
            {
                Temp[i] = m_string[i];
            }

            delete[] m_string;

            m_string = Temp;
            str_capacity = newStr_capacity;
        }
        // добавляем новый символ в буфер
        m_string[m_length] = ch;
        m_length++;
    }
    m_string[m_length] = '\0';
    std::cout << "Введено и записано" << m_string << std::endl;
}
