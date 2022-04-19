#include "Point3d.h"

Point3D::Point3D(): m_x{0}, m_y{0}, m_z{0} {}

Point3D::Point3D(double x, double y, double z): m_x{x}, m_y{y}, m_z{z} {}

Point3D::Point3D(const Point3D& point): m_x{point.m_x}, m_y{point.m_y}, m_z{point.m_z} {}

double Point3D::getX()
{
    return m_x;
}

double Point3D::getY()
{
    return m_y;
}

double Point3D::getZ()
{
    return m_z;
}

Point3D& Point3D::setX(double x)
{
    m_x = x;
    return *this;
}

Point3D& Point3D::setY(double y)
{
    m_y = y;
    return *this;
}

Point3D& Point3D::setZ(double z)
{
    m_z = z;
    return *this;
}

Point3D& Point3D::addPoints(const Point3D& point)
{
    this->m_x += point.m_x;
    this->m_y += point.m_y;
    this->m_z += point.m_z;
    return *this;
}

Point3D& Point3D::subtractPoints(const Point3D& point)
{
    this->m_x -= point.m_x;
    this->m_y -= point.m_y;
    this->m_z -= point.m_z;
    return *this;
}

double Point3D::multiplyPoints(const Point3D& point)
{
    return (this->m_x * point.m_x) + (this->m_y * point.m_y) + (this->m_z * point.m_z);
}

double Point3D::squarePoint()
{
    return (this->m_x * this->m_x) + (this->m_y * this->m_y) + (this->m_z * this->m_z);
}