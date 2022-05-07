#pragma once
#ifndef SRC_COLORBLOB_H
#define SRC_COLORBLOB_H

#include "Color.h"
#include <iostream>

class ColorBlob
{
private:
    int m_width;
    int m_height;
    Color** m_data;

public:
    ColorBlob();
    ColorBlob(int width, int height, Color color);
    ColorBlob(const ColorBlob& other);
    ColorBlob(ColorBlob&&);
    ~ColorBlob();
    void operator=(const ColorBlob& other);
    ColorBlob& operator=(ColorBlob&& other);
    friend bool operator==(const ColorBlob& cBlobOne, const ColorBlob& cBlobTwo);
    friend ColorBlob operator+(const ColorBlob &cBlobOne, const ColorBlob &cBlobTwo);
    friend ColorBlob operator-(const ColorBlob &cBlobOne, const ColorBlob &cBlobTwo);
    friend ColorBlob operator*(const ColorBlob &cBlobOne, const Color &c);
    friend bool operator! (const ColorBlob &cBlob);
    friend std::ostream& operator<<(std::ostream& stream, const ColorBlob&);
    friend std::istream& operator>>(std::istream& stream, ColorBlob&);
};

#endif