#ifndef POINT_2D_H
#define POINT_2D_H

#include "../config/config.hpp"

namespace ard
{
    class Point2D
    {
    public:
        double x;
        double y;

        Point2D();
        Point2D(double x1, double y1);

        void operator+=(const Point2D& point2D);
        void operator-=(const Point2D& point2D);

        Point2D operator*(double number);
        Point2D operator/(double number);

        Point2D operator+(const Point2D& point2D) const;
        Point2D operator-(const Point2D& point2D) const;

        Point2D normalize();
        double abs();
    };

    int sign(double number)
    {
        return number >= 0 ? 1 : -1;
    }

    double cross(Point2D p1, Point2D p2)
    {
        return p1.x * p2.y - p1.y * p2.x;
    }
}

#endif // POINT_2D_H