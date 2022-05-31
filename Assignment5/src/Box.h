#ifndef SRC_BOX_H
#define SRC_BOX_H

#include "Shape3D.h"
class Box: public Shape3D
{
private:
    double m_width;
    double m_height;
    double m_length;

public:
    Box(std::string name, double width, double height, double length):
        Shape3D(name),
        m_width{width},
        m_height{height},
        m_length{length} {}

    double computeArea() override;
    double computeVolume() override;
    void printDetail() override;
};

#endif /* SRC_BOX_H */
