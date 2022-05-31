#pragma once
#ifndef SRC_SHAPE3D_H
#define SRC_SHAPE3D_H

#include "Shape2D.h"

class Shape3D: public Shape2D
{

public:
    Shape3D(std::string& name): Shape2D(name){}
    virtual double computeVolume() = 0;

    std::string getType() override
    {
        return "Shape3D";
    }
};

#endif