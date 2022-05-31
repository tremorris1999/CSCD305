#pragma once
#ifndef SRC_SHAPE_H
#define SRC_SHAPE_H

#include <string>

class Shape
{

protected:
    std::string m_name;

public:
    Shape(const std::string& name):
        m_name{name}{}
    virtual ~Shape(){}
    const double PI = 3.14159265358979;
    virtual void printDetail() = 0;
    virtual std::string getType() = 0;

};

#endif