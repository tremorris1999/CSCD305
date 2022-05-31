#include "Circle.h"
#include <iostream>

double Circle::computeArea()
{
    return m_radius * m_radius * PI;
}

void Circle::printDetail()
{
    std::cout << m_name << ", " << getType() << ", radius: " << m_radius << ", area: " << computeArea() << std::endl; 
}