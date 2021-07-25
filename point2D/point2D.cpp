#include "point2D.hpp"

using namespace ard;

Point2D::Point2D() : x(0), y(0)
    {}

Point2D::Point2D(double x1, double y1) : x(x1), y(y1)
    {}

void Point2D::operator+=(const Point2D& point2D)
{
    this->x += point2D.x; this->y += point2D.y;
}

void Point2D::operator-=(const Point2D& point2D)
{
    this->x -= point2D.x; this->y -= point2D.y;
}

Point2D Point2D::operator*(double number)
{
    return { this->x *= number, this->y *= number };
}

Point2D Point2D::operator/(double number)
{
    return { this->x /= number, this->y /= number };
}

Point2D Point2D::operator+(const Point2D& point2D) const
{
    return { this->x + point2D.x, this->y + point2D.y };
}

Point2D Point2D::operator-(const Point2D& point2D) const
{
    return { this->x - point2D.x, this->y - point2D.y };
}

Point2D Point2D::normalize()
{
    return Point2D{ this->x / abs(), this->y / abs() };
}

double Point2D::abs()
{
    return sqrt(x * x + y * y);
}

int sign(double number)
{
    return number >= 0 ? 1 : -1;
}

double cross(Point2D p1, Point2D p2)
{
    return p1.x * p2.y - p1.y * p2.x;
}