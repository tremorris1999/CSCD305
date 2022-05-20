#pragma once
#ifndef SRC_POINT3D_H
#define SRC_POINT3D_H

class Point3D
{
private:
    double m_x, m_y, m_z;

public:
    Point3D();
    Point3D(double x, double y, double z);
    Point3D(const Point3D& point);
    Point3D& setX(double x);
    Point3D& setY(double y);
    Point3D& setZ(double z);
    double getX();
    double getY();
    double getZ();
    Point3D& addPoints(const Point3D& point);
    Point3D& subtractPoints(const Point3D& point);
    double multiplyPoints(const Point3D& point);
    double squarePoint();
};

#endif