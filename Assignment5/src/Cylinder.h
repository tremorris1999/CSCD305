#ifndef SRC_CYLINDER_H
#define SRC_CYLINDER_H

#include "Shape3D.h"
class Cylinder: public Shape3D
{
private:
    double m_height;
    double m_radius;

public:
    Cylinder(std::string name, double radius, double length):
        Shape3D(name),
        m_radius{radius},
        m_height{length} {}

    double computeArea() override;
    double computeVolume() override;
    void printDetail() override;
};

#endif /* SRC_CYLINDER_H */
