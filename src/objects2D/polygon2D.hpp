#ifndef POLYGON_2D_H
#define POLYGON_2D_H

#include "object2D.hpp"

namespace ard
{
    class Polygon2D : public Object2D
    {
    public:
        explicit Polygon2D(std::vector<Point2D> points2D = {}, Point2D position = { 0, 0 }, std::string texture = WALL_TEXTURE) :
            Object2D(position, points2D, texture)
        {}

        void add_point(double x, double y)
        {
             nodes().push_back({ x, y });
        }

        void add_point(Point2D position)
        {
             nodes().push_back(position);
        }
    };
};

#endif // POLYGON_2D_H