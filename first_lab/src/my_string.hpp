#pragma once
#include <cstddef>

class MyString
{
private:
    char *m_string;
    size_t m_length;

public:
    MyString();

    MyString(const char *length);
    MyString(const MyString &other);

    char get(int i) const;              // получение i-того элемента строки
    void set(int i, char c);            // установка i-того элемента строки
    void setNewString(const char *str); // замена текущего содержимого на новое
    void print() const;                 // вывод строки в консоль
    void readLine();                    // замена текущего содержимого строки на строку, считанную с консоли (неопределенного размера).
};
