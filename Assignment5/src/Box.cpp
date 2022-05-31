#include "Box.h"
#include <iostream>

double Box::computeArea()
{
    return (2 * m_height * m_length) + (2 * m_height * m_width) + (2 * m_width * m_length);
}

double Box::computeVolume()
{
    return m_width * m_height * m_length;
}

void Box::printDetail()
{
    std::cout << m_name << ", " << getType() << ", width: " << m_width << ", height: " << m_height << ", depth: " << m_length << ", area: " << computeArea() << ", volume: " << computeVolume() << std::endl; 
}