#pragma once
#ifndef SRC_SHAPE2D_H
#define SRC_SHAPE2D_H

#include "Shape.h"

class Shape2D: public Shape
{

public:
    Shape2D(std::string& name): Shape(name){}
    virtual double computeArea() = 0;

    std::string getType() override
    {
        return "Shape2D";
    }
};

#endif