#include "Cylinder.h"
#include <iostream>

double Cylinder::computeArea()
{
    return (2 * PI * m_radius * m_height) + (2 * PI * m_radius * m_radius);
}

double Cylinder::computeVolume()
{
    return m_radius * m_radius * PI * m_height;
}

void Cylinder::printDetail()
{
    std::cout << m_name << ", " << getType() << ", radius: " << m_radius << ", height: " << m_height << ", area: " << computeArea() << ", volume: " << computeVolume() << std::endl; 
}