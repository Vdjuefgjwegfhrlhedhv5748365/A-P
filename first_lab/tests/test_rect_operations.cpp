#include <iostream>
#include "../src/rect.hpp"
#include <cassert>
int main()
{

    {
        std::cout << "Тест 1. Метод inflate" << std::endl;
        Rect r1(5, 15, 5, 25);
        r1.inflate(5);
        assert(r1.getLeft() == 0);
        assert(r1.getBottom() == 0);
        assert(r1.getRight() == 30);
        assert(r1.getTop() == 20);
        std::cout << "Метод inflate с одним введенным параметром работает корректно" << std::endl;
    }

    {
        std::cout << "Тест 2. Метод inflate" << std::endl;
        Rect r2;
        r2.inflate(2, 7);
        assert(r2.getLeft() == -2);
        assert(r2.getBottom() == -7);
        assert(r2.getRight() == 2);
        assert(r2.getTop() == 7);
        std::cout << "Метод inflate с двумя введенными параметрами работает корректно" << std::endl;
    }

    {
        std::cout << "Тест 3. Метод inflate" << std::endl;
        Rect r3(10, 20, 30, 40);
        r3.inflate(40, 30, 20, 10);
        assert(r3.getBottom() == -30);
        assert(r3.getTop() == 50);
        assert(r3.getLeft() == 10);
        assert(r3.getRight() == 50);
        std::cout << "Метод inflate с четырьмя введенными параметрами работает корректно" << std::endl;
    }

    {
        std::cout << "Тест 4. Метод move" << std::endl;
        Rect r4(0, 5, 10, 15);
        r4.move(5, -5);
        assert(r4.getLeft() == 15);
        assert(r4.getBottom() == -5);
        assert(r4.getRight() == 20);
        assert(r4.getTop() == 0);
        std::cout << "Метод move работает корректно" << std::endl;
    }
    return 0;
}