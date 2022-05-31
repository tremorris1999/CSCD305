#include "Sphere.h"
#include <iostream>

double Sphere::computeArea()
{
    return 4 * m_radius * m_radius * PI;
}

double Sphere::computeVolume()
{
    return (4.0 / 3.0) * m_radius * m_radius * m_radius * PI;
}

void Sphere::printDetail()
{
    std::cout << m_name << ", " << getType() << ", radius: " << m_radius << ", area: " << computeArea() << ", volume: " << computeVolume() << std::endl; 
}