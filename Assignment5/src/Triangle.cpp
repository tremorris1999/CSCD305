#include "Triangle.h"
#include <iostream>

double Triangle::computeArea()
{
    return 0.5 * m_base * m_height;
}

void Triangle::printDetail()
{
    std::cout << m_name << ", " << getType() << ", base: " << m_base << ", height: " << m_height << ", area: " << computeArea() << std::endl; 
}