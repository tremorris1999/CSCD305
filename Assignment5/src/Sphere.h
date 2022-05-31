#ifndef SRC_SPHERE_H
#define SRC_SPHERE_H

#include "Shape3D.h"
class Sphere: public Shape3D
{
private:
    double m_radius;

public:
    Sphere(std::string name, double radius):
        Shape3D(name),
        m_radius{radius} {}

    double computeArea() override;
    double computeVolume() override;
    void printDetail() override;
};

#endif /* SRC_SPHERE_H */
