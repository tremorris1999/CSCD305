#ifndef SRC_CIRCLE_H
#define SRC_CIRCLE_H

#include "Shape2D.h"
class Circle: public Shape2D
{
private:
    double m_radius;

public:
    Circle(std::string name, double radius):
        Shape2D(name),
        m_radius{radius} {}

    double computeArea() override;
    void printDetail() override;
};

#endif /* SRC_CIRCLE_H */
