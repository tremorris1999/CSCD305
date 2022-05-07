#include "Color.h"
#include <vector>

void Color::clamp()
{
    if(m_red < 0.0)
        m_red = 0.0;
    if(m_green < 0.0)
        m_green = 0.0;
    if(m_blue < 0.0)
        m_blue = 0.0;

    if(m_red > 1.0)
        m_red = 1.0;
    if(m_green > 1.0)
        m_green = 1.0;
    if(m_blue > 1.0)
        m_blue = 1.0;
}

Color::Color(): m_red{0.5}, m_green{0.5}, m_blue{0.5} {}

Color::Color(double red, double green, double blue)
    : m_red{red},
    m_green{green},
    m_blue{blue}
{
    clamp();
}

Color::Color(const Color& other)
    : Color{other.m_red, other.m_green, other.m_blue}{}

Color& Color::operator=(const Color& other)
{
    m_red = other.m_red;
    m_green = other.m_green;
    m_blue = other.m_blue;
    return *this;
}

void Color::setRed(double value)
{
    m_red = value;
    clamp();
}

void Color::setGreen(double value)
{
    m_green = value;
    clamp();
}

void Color::setBlue(double value)
{
    m_blue = value;
    clamp();
}

double Color::getRed()
{
    return m_red;
}

double Color::getGreen()
{
    return m_green;
}

double Color::getBlue()
{
    return m_blue;
}

bool operator==(const Color& colorOne, const Color& colorTwo)
{
    if(&colorOne == &colorTwo)
        return true;

    if(colorOne.m_red == colorTwo.m_red
        && colorOne.m_green == colorTwo.m_green
        && colorOne.m_blue == colorTwo.m_blue)
        return true;

    return false;
}

Color operator+(const Color& colorOne, const Color& colorTwo)
{
    Color c = Color(colorOne.m_red + colorTwo.m_red, colorOne.m_green + colorTwo.m_green, colorOne.m_blue + colorTwo.m_blue);
    c.clamp();
    return c;
}

Color operator-(const Color& colorOne, const Color& colorTwo)
{
    Color c = Color(colorOne.m_red - colorTwo.m_red, colorOne.m_green - colorTwo.m_green, colorOne.m_blue - colorTwo.m_blue);
    c.clamp();
    return c;
}

Color operator*(const Color& colorOne, const Color& colorTwo)
{
    Color c = Color(colorOne.m_red * colorTwo.m_red, colorOne.m_green * colorTwo.m_green, colorOne.m_blue * colorTwo.m_blue);
    c.clamp();
    return c;
}

bool operator!(const Color& colorOne)
{
    return !(colorOne.m_red == 0.0 && colorOne.m_green == 0.0 && colorOne.m_blue == 0.0);
}

std::ostream& operator<<(std::ostream& stream, const Color& color)
{
    stream << "(" << color.m_red << ", " << color.m_green << ", " << color.m_blue << ")";
    return stream;
}

std::istream& operator>>(std::istream& stream, Color& color)
{
    auto split = [](std::string string, std::string delimiter)
	{
		std::vector<std::string> out;
		size_t position = 0;
		std::string token;
		while ((position = string.find(delimiter)) != std::string::npos)
		{
			out.push_back(string.substr(0, position));
			string.erase(0, position + delimiter.length());
		}
		
		out.push_back(string);
		return out;
	};

    stream >> color.m_red >> color.m_green >> color.m_blue;
    return stream;
}