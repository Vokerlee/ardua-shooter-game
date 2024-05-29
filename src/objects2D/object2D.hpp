#ifndef OBJ_2D_H
#define OBJ_2D_H

#include "config/config.hpp"
#include "config/drawable.hpp"
#include "point2D/point2D.hpp"

namespace ard
{
    class Object2D : virtual public Drawable
    {
    private:
        Point2D position_;
        Point2D velocity_;

        std::vector<Point2D> points2D_;

        std::string name_;

        sf::Texture texture_;
        std::string s_texture_;

        bool texture_loaded_ = false;

    public:
        Object2D(Point2D position = { 0, 0 }, std::vector<Point2D> points = {}, 
                 std::string texture = WALL_TEXTURE, Point2D velocity = { 0, 0 });

        double x();
        double y();
        const Point2D position();

        void set_position(Point2D position);
        void set_position(double x, double y);
        void shift(Point2D vector);

        void set_name(std::string name);
        std::string get_name();

        std::vector<Point2D>& nodes();

        sf::Texture& load_texture();

        void draw(sf::RenderWindow& window) override;

        static bool vector_crossing(std::pair<Point2D, Point2D> segment1, 
                                    std::pair<Point2D, Point2D> segment2, Point2D& point);
    };
};

#endif // OBJ_2D_H