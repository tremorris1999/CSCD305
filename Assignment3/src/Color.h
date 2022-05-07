#pragma once
#ifndef SRC_COLOR_H
#define SRC_COLOR_H

#include <iostream>

class Color
{
private:
    double m_red, m_green, m_blue;
    void clamp();

public:
    Color();
    Color(double red, double green, double blue);
    Color(const Color& other);
    Color& operator=(const Color& other);
    void setRed(double value);
    void setGreen(double value);
    void setBlue(double value);
    double getRed();
    double getGreen();
    double getBlue();
    friend bool operator==(const Color& colorOne, const Color& colorTwo);
    friend Color operator+(const Color& colorOne, const Color& colorTwo);
    friend Color operator-(const Color& colorOne, const Color& colorTwo);
    friend Color operator*(const Color& colorOne, const Color& colorTwo);
    friend bool operator!(const Color& colorOne);
    friend std::ostream& operator<<(std::ostream& stream, const Color& color);
    friend std::istream& operator>>(std::istream& stream, Color& color);
};

#endif