#include <cmath>
#include <vector>
#include <algorithm>

class Point {
private:
    double m_x {};
    double m_y {};

public:
    Point(double x = 0, double y = 0)
        : m_x { x }
        , m_y { y }
    {
    }

public:
    double getX() const
    {
        return m_x;
    }
    double getY() const
    {
        return m_y;
    }
    void setX(const double x)
    {
        m_x = x;
    }
    void setY(const double y)
    {
        m_y = y;
    }

public:
    double distance(const Point& point)
    {
        return std::sqrt(std::pow(m_x - point.getX(), 2) + std::pow(m_y - point.getY(), 2));
    }
};

class Device {
private:
    inline static std::size_t ms_deviceCount;
    inline static std::vector<Point> ms_deviceCoords;
    Point m_location {};
    std::size_t m_ID {};
    double m_range {};

public:
    Device(std::size_t id, double range, double x = 0, double y = 0)
        : m_location { x, y }
        , m_ID { id }
        , m_range { range }
    {
        ms_deviceCount += 1;
        ms_deviceCoords.emplace_back(x, y);
    }

public:
    const Point& getLocation() const
    {
        return m_location;
    }
    std::size_t getID() const
    {
        return m_ID;
    }
    double getRange() const
    {
        return m_range;
    }
    std::size_t getDeviceCount() const
    {
        return ms_deviceCount;
    }

public:
    void setLocation(const double x, const double y)
    {
        m_location.setX(x);
        m_location.setY(y);
    }
    void setRange(double range)
    {
        m_range = range;
    }

public:
    const std::size_t getNeighbourCount()
    {
        // 1 is subtracted because the device itself is also counted in the neighbour
        return std::count_if(ms_deviceCoords.cbegin(), ms_deviceCoords.cend(), [&](const Point& point) {
            return m_location.distance(point) <= m_range;
        }) - 1;
    }
};

int main()
{
}