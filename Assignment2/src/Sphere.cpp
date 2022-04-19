#include "Sphere.h"

Sphere::Sphere(): m_center{Point3D(0, 0, 0)}, m_radius{1} {}

Sphere::Sphere(Point3D& center, double radius): m_center{center}, m_radius{radius} {}

Point3D& Sphere::getCenter()
{
    return this->m_center;
}

double Sphere::getRadius()
{
    return this->m_radius;
}