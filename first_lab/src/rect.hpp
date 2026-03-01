#pragma once
#include <iostream>
class Rect
{
private:
    int m_bottom;
    int m_top;
    int m_left;
    int m_right;
    void FlipIfIncorrect();

public:
    // конструктор по умолчанию
    Rect();
    // конструктор с 4-мя параметрами
    Rect(int bottom, int top, int left, int right);
    // конструктор копирования
    Rect(const Rect &other);
    // деструктор
    ~Rect();

    int getLeft() const { return m_left; }
    int getRight() const { return m_right; }
    int getTop() const { return m_top; }
    int getBottom() const { return m_bottom; }

    void setAll(int bottom, int top, int left, int right);

    void inflate(int amount);
    void inflate(int dw, int dh);
    void inflate(int dBottom, int dTop, int dLeft, int dRight);

    void move(int dx = 0, int dy = 0);
    int getWidth() const { return m_right - m_left; }
    int getHeight() const { return m_top - m_bottom; }
    int getSquare() const { return (getWidth() * getHeight()); }

    void setWidth(int width) { m_right = m_left + width; }
    void setHeight(int height) { m_top = m_bottom + height; }
};

Rect boundingRect(const Rect &r1, const Rect &r2);
void printRect(const Rect &r);
