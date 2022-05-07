#include "ColorBlob.h"

ColorBlob::ColorBlob(): m_width{2}, m_height{2}
{
    m_data = new Color*[2];
    for(int i = 0; i < 2; i++)
    {
        m_data[i] = new Color[m_height];
        for(int j = 0; j < 2; j++)
            m_data[i][j] = Color();
    }  
}

ColorBlob::ColorBlob(int width, int height, Color color): m_width{width}, m_height{height}
{
    m_data = new Color*[m_width];
    for(int i = 0; i < width; i++)
    {
        m_data[i] = new Color[m_height];
        for(int j = 0; j < height; j++)
            m_data[i][j] = color;
    }      
}

ColorBlob::ColorBlob(const ColorBlob& other): m_width{other.m_width}, m_height{other.m_height}
{
    m_data = new Color*[m_width];
    for(int i = 0; i < other.m_width; i++)
    {
        m_data[i] = new Color[m_height];
        for(int j = 0; j < other.m_height; j++)
            m_data[i][j] = other.m_data[i][j];
    }
}

ColorBlob::ColorBlob(ColorBlob&& other): m_width{other.m_width}, m_height{other.m_height}
{
    m_data = other.m_data;
    other.m_data = nullptr;
}

ColorBlob::~ColorBlob()
{
    if(m_data)
    {
        for(int i = 0; i < m_width; i++)
            delete[] m_data[i];

        delete[] m_data;
    }
}

void ColorBlob::operator=(const ColorBlob& other)
{
    m_width = other.m_width;
    m_height = other.m_height;  
    m_data = other.m_data;
}

ColorBlob& ColorBlob::operator=(ColorBlob&& other)
{
    delete[] m_data;
    m_width = other.m_width;
    m_height = other.m_height;
    m_data = other.m_data;
    other.m_data = nullptr;

    return *this;
}

bool operator==(const ColorBlob& cBlobOne, const ColorBlob& cBlobTwo)
{
    if(cBlobOne.m_width != cBlobTwo.m_width || cBlobOne.m_height != cBlobTwo.m_height)
        return false;
    
    for(int i =0; i < cBlobOne.m_width; i++)
        for(int j = 0; j < cBlobOne.m_height; j++)
            if(!(cBlobOne.m_data[i][j] == cBlobTwo.m_data[i][j]))
                return false;

    return true;
}

ColorBlob operator+(const ColorBlob &cBlobOne, const ColorBlob &cBlobTwo)
{
    ColorBlob blob(
        (cBlobOne.m_width < cBlobTwo.m_width ? cBlobOne.m_width : cBlobTwo.m_width),
        (cBlobOne.m_height < cBlobTwo.m_height ? cBlobOne.m_height : cBlobTwo.m_height), 
        Color());

    for(int i = 0; i < blob.m_width; i++)
        for(int j = 0; j < blob.m_height; j++)
            blob.m_data[i][j] = cBlobOne.m_data[i][j] + cBlobTwo.m_data[i][j];

    return blob;
}

ColorBlob operator-(const ColorBlob &cBlobOne, const ColorBlob &cBlobTwo)
{
    ColorBlob blob(
        (cBlobOne.m_width < cBlobTwo.m_width ? cBlobOne.m_width : cBlobTwo.m_width),
        (cBlobOne.m_height < cBlobTwo.m_height ? cBlobOne.m_height : cBlobTwo.m_height), 
        Color());

    for(int i = 0; i < blob.m_width; i++)
        for(int j = 0; j < blob.m_height; j++)
            blob.m_data[i][j] = cBlobOne.m_data[i][j] - cBlobTwo.m_data[i][j];

    return blob;
}

ColorBlob operator*(const ColorBlob &cBlobOne, const Color &c)
{
    for(int i = 0; i < cBlobOne.m_width; i++)
        for(int j = 0; j < cBlobOne.m_height; j++)
            cBlobOne.m_data[i][j] = cBlobOne.m_data[i][j] * c;
    
    return cBlobOne;
}

bool operator! (const ColorBlob &cBlob)
{
    for(int i = 0; i < cBlob.m_width; i++)
        for(int j = 0; j < cBlob.m_height; j++)
            if(!!cBlob.m_data[i][j])
                return true;

    return false;
}

std::ostream& operator<<(std::ostream& stream, const ColorBlob& cBlob)
{
    for(int i = 0; i < cBlob.m_width; i++)
        for(int j = 0; j < cBlob.m_height; j++)
            stream << "[" << i << "][" << j << "]: " << cBlob.m_data[i][j] << std::endl;

    return stream;
}

std::istream& operator>>(std::istream& stream, ColorBlob& cBlob)
{
    for(int i = 0; i < cBlob.m_width; i++)
        for(int j = 0; j < cBlob.m_height; j++)
        {
            std::cout << "[" << i << "][" << j << "]: \"R G B\" <--- ";
            stream >> cBlob.m_data[i][j];
            std::cout << std::endl;
        }

    return stream;
}


