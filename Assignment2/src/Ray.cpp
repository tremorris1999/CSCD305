/**
 * @file Ray.cpp
 * @author Trevor Morris (00876703) (tmorris17@ewu.edu)
 * 
 * I am personally running clang++ for my compiler, but I'm using CMake for
 * building the project, so it should work with g++ or MSVC no problem.
 * 
 */

#include "Ray.h"
#include <iostream>

Ray::Ray(): m_origin{Point3D(0.0, 0.0, 0.0)}, m_direction{Point3D(0, 0, 0)} {}

Ray::Ray(Point3D& origin, Point3D& direction): m_origin{origin}, m_direction{direction} {}

Point3D& Ray::getOrigin()
{
    return this->m_origin;
}

Point3D& Ray::getDirection()
{
    return this->m_direction;
}

void Ray::checkIntersection(Sphere& sphere)
{
    double A = this->m_direction.squarePoint();
    this->m_origin.subtractPoints(sphere.getCenter());
    double B = this->m_origin.multiplyPoints(this->m_direction);
    double r_squared = sphere.getRadius() * sphere.getRadius();
    double C = this->m_origin.squarePoint() - r_squared;
    double res = B*B - A*C;
    std::cout << res << std::endl;
    std::string message = res < 0 ? "Ray does not touch or intersect the sphere." : "Ray either touches or intersects the sphere.";
    std::cout << message << std::endl;
}