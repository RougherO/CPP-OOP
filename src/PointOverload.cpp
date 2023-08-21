#include <cmath>
#include <iostream>

class Point {
private:
    double m_x {}, m_y {};

public:
    Point(double x = 0, double y = 0)
        : m_x { x }
        , m_y { y }
    {
    }

    Point(const Point&) = default;
    Point& operator=(const Point&) = default;

public:
    double getX() const
    {
        return m_x;
    }

    double getY() const
    {
        return m_y;
    }

public:
    void setX(double x)
    {
        m_x = x;
    }

    void setY(double y)
    {
        m_y = y;
    }

public:
    double operator-(const Point& other)
    {
        return std::sqrt(std::pow(other.m_x - m_x, 2) + std::pow(other.m_y - m_y, 2));
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& point)
    {
        return os << "(" << point.m_x << ", " << point.m_y << ")";
    }
};
