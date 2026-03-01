#include "rect.hpp"
#include <iostream>
Rect ::Rect()
{
    this->m_bottom = 0;
    this->m_top = 0;
    this->m_left = 0;
    this->m_right = 0;
    std::cout << "Конструктор по умолчанию вызван, поля класса проинициализированны нулями. Адрес:" << this << std::endl;
}

Rect::Rect(int bottom, int top, int left, int right) : m_bottom(bottom), m_top(top), m_left(left), m_right(right)
{
    FlipIfIncorrect();
    std::cout << "Конструктор с 4-мя параметрами вызван, поля структуры проинициализированны заданными значениями. Адрес:" << this << std::endl;
}
void Rect::FlipIfIncorrect()
{
    if (m_left > m_right)
    {
        int temp = m_right;
        m_right = m_left;
        m_left = temp;
    }

    if (m_bottom > m_top)
    {
        int temp = m_bottom;
        m_bottom = m_top;
        m_top = temp;
    }
}
Rect::Rect(const Rect &other)
{
    this->m_bottom = other.m_bottom;
    this->m_top = other.m_top;
    this->m_left = other.m_left;
    this->m_right = other.m_right;
    std::cout << "Конструктор копирования вызван. Новый адрес:" << this << std::endl;
}

Rect ::~Rect()
{
    std::cout << "Деструктор вызван. Адрес: " << this << std::endl;
}

void Rect ::setAll(int bottom, int top, int left, int right)
{

    this->m_bottom = bottom;
    this->m_top = top;
    this->m_left = left;
    this->m_right = right;

    FlipIfIncorrect();
}

void Rect ::inflate(int amount)
{
    inflate(amount, amount);
}

void Rect ::inflate(int dw, int dh)
{
    inflate(dh, dh, dw, dw);
}

void Rect ::inflate(int dBottom, int dTop, int dLeft, int dRight)
{
    m_bottom -= dBottom;
    m_top += dTop;
    m_left -= dLeft;
    m_right += dRight;
    FlipIfIncorrect();
}

void Rect ::move(int dx, int dy)
{
    m_left += dx;
    m_right += dx;
    m_top += dy;
    m_bottom += dy;
}

Rect boundingRect(const Rect &r1, const Rect &r2)
{
    int left_bound = std::min(r1.getLeft(), r2.getLeft());
    int right_bound = std::max(r1.getRight(), r2.getRight());
    int top_bound = std::max(r1.getTop(), r2.getTop());
    int bottom_bound = std::min(r1.getBottom(), r2.getBottom());

    return Rect(bottom_bound, top_bound, left_bound, right_bound);
}

void printRect(const Rect &r)
{
    int width = r.getRight() - r.getLeft();
    int height = r.getTop() - r.getBottom();

    if (width <= 0 || height <= 0)
    {
        std::cout << "Пустой прямоугольник" << std::endl;
        return;
    }

    std::cout << "+";
    for (int i = 0; i < width; i++)
    {
        std::cout << "-";
    }
    std::cout << "+" << std::endl;

    for (int i = 0; i < height; i++)
    {
        std::cout << "|";
        for (int j = 0; j < width; j++)
        {
            std::cout << " ";
        }
        std::cout << "|" << std::endl;
    }

    std::cout << "+";
    for (int i = 0; i < width; i++)
    {
        std::cout << "-";
    }
    std::cout << "+" << std::endl;
}