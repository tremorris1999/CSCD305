#pragma once
#ifndef SRC_RAY_H
#define SRC_RAY_H

#include "Point3d.h"
#include "Sphere.h"

class Ray
{
private:
    Point3D m_origin, m_direction;

public:
    Ray();
    Ray(Point3D& origin, Point3D& direction);
    Point3D& getOrigin();
    Point3D& getDirection();
    void checkIntersection(Sphere& sphere);

    friend class Sphere;
};

#endif