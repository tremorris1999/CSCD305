#include "Rectangle.h"
#include <iostream>

double Rectangle::computeArea()
{
    return m_width * m_height;
}

void Rectangle::printDetail()
{
    std::cout << m_name << ", " << getType() << ", width: " << m_width << ", height: " << m_height << ", area: " << computeArea() << std::endl; 
}