#include <iostream>
#include "../src/rect.hpp"
#include <cassert>
int main()
{
    {
        std::cout << "Tect 1. Проверка конструктора по умолчанию (поля заполняются нулями) " << std::endl;
        Rect r1;
        assert(r1.getBottom() == 0);
        assert(r1.getTop() == 0);
        assert(r1.getLeft() == 0);
        assert(r1.getRight() == 0);
    }

    {
        std::cout << "Tect 2. Проверка конструктора с 4-мя параметрами" << std::endl;
        Rect r2(2, 4, 4, 6);
        assert(r2.getBottom() == 2);
        assert(r2.getTop() == 4);
        assert(r2.getLeft() == 4);
        assert(r2.getRight() == 6);
    }

    {
        std::cout << "Tect 3. Проверка конструктора копирования" << std::endl;
        Rect r3(-8, 2, 0, 5);
        Rect r4(r3);
        assert(r3.getBottom() == r4.getBottom());
        assert(r3.getTop() == r4.getTop());
        assert(r3.getLeft() == r4.getLeft());
        assert(r3.getRight() == r4.getRight());
    }

    {
        std::cout << "Tect 4. Метода setAll  " << std::endl;
        Rect r5;
        r5.setAll(2, 4, 6, 8);
        assert(r5.getBottom() == 2);
        assert(r5.getTop() == 4);
        assert(r5.getLeft() == 6);
        assert(r5.getRight() == 8);
    }

    {
        std::cout << "Tect 5. Метода setAll (пользователь перепутал bottom and top, left and right) " << std::endl;
        Rect r6;
        r6.setAll(4, 2, 8, 6);
        assert(r6.getBottom() == 2);
        assert(r6.getTop() == 4);
        assert(r6.getLeft() == 6);
        assert(r6.getRight() == 8);
    }

    {
        std::cout << "Tect 6. Метода setAll (пользователь перепутал bottom and top) " << std::endl;
        Rect r5;
        r5.setAll(20, 4, 6, 8);
        assert(r5.getBottom() == 4);
        assert(r5.getTop() == 20);
        assert(r5.getLeft() == 6);
        assert(r5.getRight() == 8);
    }

    {
        std::cout << "Tect 1. Метода setAll (пользователь перепутал bottom and top, left and right) " << std::endl;
        Rect r5;
        r5.setAll(2, 4, 63, 1);
        assert(r5.getBottom() == 2);
        assert(r5.getTop() == 4);
        assert(r5.getLeft() == 1);
        assert(r5.getRight() == 63);
    }

    return 0;
}