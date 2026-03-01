#include <iostream>
#include "../src/rect.hpp"
#include <cassert>
int main()
{
    {
        std::cout << "Тест 1. Методы getWidth и getHeight" << std::endl;
        Rect rect1(0, 5, 0, 15);
        assert(rect1.getWidth() == 15);
        assert(rect1.getHeight() == 5);
        std::cout << "Методы getWidth и getHeight работают корректно" << std::endl;
    }

    {
        std::cout << "Тест 2. Метод getSquare" << std::endl;
        Rect rect2(0, 2, 0, 3);
        assert(rect2.getSquare() == 6);
    }

    {
        std::cout << "Тест3. Методы setWidth и set_height" << std::endl;
        Rect rect3;
        rect3.setWidth(20);
        rect3.setHeight(40);
        assert(rect3.getRight() - rect3.getLeft() == 20);
        assert(rect3.getTop() - rect3.getBottom() == 40);
    }

    return 0;
}