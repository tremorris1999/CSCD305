#ifndef SRC_TRIANGLE_H
#define SRC_TRIANGLE_H

#include "Shape2D.h"
class Triangle: public Shape2D
{
private:
    double m_base;
    double m_height;

public:
    Triangle(std::string name, double base, double height):
        Shape2D(name),
        m_base{base},
        m_height{height} {}

    double computeArea() override;
    void printDetail() override;
};

#endif /* SRC_TRIANGLE_H */
