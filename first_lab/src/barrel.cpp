#include "barrel.hpp"
#include <algorithm>
#include <iostream>

Barrel::Barrel(double capacity, double initial_concentration) : m_alcohol(capacity * initial_concentration), m_water(capacity * (1.0 - initial_concentration)) {}

double Barrel::getTotalAmount() const
{
    return m_alcohol + m_water;
}

double Barrel::getConcentration() const
{
    double total = getTotalAmount();
    return (m_alcohol / total) * 100.0;
}

void Barrel::pourInto(Barrel &other, double cap_capacity)
{

    double alcoholToPour = (m_alcohol / other.getTotalAmount()) * cap_capacity;
    double waterToPour = (m_water / other.getTotalAmount()) * cap_capacity;

    m_alcohol -= alcoholToPour;
    m_water -= waterToPour;

    other.m_alcohol += alcoholToPour;
    other.m_water += waterToPour;
}

void Barrel::Iteration(Barrel &other, double cap_capacity)
{
    pourInto(other, cap_capacity);
    other.pourInto(*this, cap_capacity);
}
