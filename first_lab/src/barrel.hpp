#pragma once

class Barrel
{
private:
    double m_alcohol;
    double m_water;

public:
    Barrel(double capacity, double initial_concentration);
    // метод получения концентрации
    double getConcentration() const;
    // получить количество жидкости в бочке
    double getTotalAmount() const;
    // итерация
    void Iteration(Barrel &other, double cap_capacity = 1);
    // метод - переливание из одной бочки в другую
    void pourInto(Barrel &other, double cap_capacity = 1);
};
