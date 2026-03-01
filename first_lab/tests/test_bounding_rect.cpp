#include <iostream>
#include "../src/rect.hpp"
#include <cassert>
int main()
{

    {
        std::cout << "Tect 1. Функция boundingRect с корректными четырьмя параметрами" << std::endl;
        Rect const r1(0, 4, 4, 8);
        Rect const r2(-3, 45, -6, 6);
        Rect const res12 = boundingRect(r1, r2);
        assert(res12.getBottom() == -3);
        assert(res12.getTop() == 45);
        assert(res12.getLeft() == -6);
        assert(res12.getRight() == 8);
    }

    {
        std::cout << "Tect 2. Функция boundingRect (пользователь перепутал Left и Right в одном прямоугольнике)" << std::endl;
        Rect const r3(0, 5, 0, 5);
        Rect const r4(-5, 0, -5, -10);
        Rect const res34 = boundingRect(r3, r4);
        assert(res34.getBottom() == -5);
        assert(res34.getTop() == 5);
        assert(res34.getLeft() == -10);
        assert(res34.getRight() == 5);
    }

    {
        std::cout << "Tect 3. Функция boundingRect (пользователь перепутал Left и Right в двух прямоугольниках)" << std::endl;
        Rect const r5(0, 5, 100, 50);
        Rect const r6(-5, 0, 45, 40);
        Rect const res56 = boundingRect(r5, r6);
        assert(res56.getBottom() == -5);
        assert(res56.getTop() == 5);
        assert(res56.getLeft() == 40);
        assert(res56.getRight() == 100);
    }

    {
        std::cout << "Tect 4. Функция boundingRect (пользователь перепутал Bottom и Top в одном прямоугольнике)" << std::endl;
        Rect const r7(5, 0, 0, 5);
        Rect const r8(-5, 0, 0, 7);
        Rect const res78 = boundingRect(r7, r8);
        assert(res78.getBottom() == -5);
        assert(res78.getTop() == 5);
        assert(res78.getLeft() == 0);
        assert(res78.getRight() == 7);
    }

    {
        std::cout << "Tect 5. Функция boundingRect (пользователь перепутал Bottom и Top в двух прямоугольниках)" << std::endl;
        Rect const r9(10, 5, 0, 5);
        Rect const r10(30, 20, -5, 10);
        Rect const res910 = boundingRect(r9, r10);
        assert(res910.getBottom() == 5);
        assert(res910.getTop() == 30);
        assert(res910.getLeft() == -5);
        assert(res910.getRight() == 10);
    }

    {
        std::cout << "Tect 6. Функция boundingRect (пользователь перепутал Left и Right, Bottom и Top в одном прямоугольнике)" << std::endl;
        Rect const r11(10, 0, 10, 0);
        Rect const r12(-5, 0, -5, 10);
        Rect const res1112 = boundingRect(r11, r12);
        assert(res1112.getBottom() == -5);
        assert(res1112.getTop() == 10);
        assert(res1112.getLeft() == -5);
        assert(res1112.getRight() == 10);
    }

    {
        std::cout << "Tect 7. Функция boundingRect (пользователь перепутал Left и Right, Bottom и Top в двух прямоугольниках)" << std::endl;
        Rect const r13(20, 10, 20, 10);
        Rect const r14(35, 30, 35, 30);
        Rect res1314 = boundingRect(r13, r14);
        assert(res1314.getBottom() == 10);
        assert(res1314.getTop() == 35);
        assert(res1314.getLeft() == 10);
        assert(res1314.getRight() == 35);
    }

    return 0;
}