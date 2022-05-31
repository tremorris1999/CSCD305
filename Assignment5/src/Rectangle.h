#ifndef SRC_RECTANGLE_H
#define SRC_RECTANGLE_H

#include "Shape2D.h"
class Rectangle: public Shape2D
{
private:
    double m_width;
    double m_height;

public:
    Rectangle(std::string name, double width, double height):
        Shape2D(name),
        m_width{width},
        m_height{height} {}

    double computeArea() override;
    void printDetail() override;
};

#endif /* SRC_RECTANGLE_H */
