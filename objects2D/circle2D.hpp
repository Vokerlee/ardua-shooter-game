#ifndef CIRCLE_2D_H
#define CIRCLE_2D_H

#include "object2D.hpp"

namespace ard
{
    class Circle2D : public Object2D
    {
    private:
        double radius_ = 0;

    public:
        explicit Circle2D(double radius = 0, Point2D position = { 0, 0 }, std::string texture = WALL_TEXTURE) :
            Object2D(position, {}, texture),
            radius_(radius)
        {
            // Storing all points of circle (CIRCLE_CONVEX_NUMBER)
            for (int i = 0; i < CIRCLE_CONVEX_NUMBER; i++)
            {
                double x = radius_ * cos(2 * PI * i / CIRCLE_CONVEX_NUMBER);
                double y = radius_ * sin(2 * PI * i / CIRCLE_CONVEX_NUMBER);

                nodes().push_back({ x, y });
            }
        }
    };
};

#endif // CIRCLE_2D_H