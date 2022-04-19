#pragma once
#ifndef SRC_SPHERE_H
#define SRC_SPHERE_H

#include "Point3d.h"

class Sphere
{
    private:
        Point3D m_center;
        double m_radius;
        
    public:
        Sphere();
        Sphere(Point3D& center, double radius);
        Point3D& getCenter();
        double getRadius();
};

#endif