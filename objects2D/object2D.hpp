#ifndef OBJ_2D_H
#define OBJ_2D_H

#include "../config/config.hpp"
#include "../config/drawable.hpp"
#include "../point2D/point2D.hpp"

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
        std::string texture_name_;

        bool texture_loaded_ = false;

    public:
        Object2D(Point2D position = { 0, 0 }, std::vector<Point2D> points = {}, std::string texture = WALL_TEXTURE, Point2D velocity = { 0, 0 });

        double x();
        double y();
        const Point2D position();

        void set_position(Point2D position);
        void set_position(double x, double y);
        void shift(Point2D vector);

        void set_name(std::string name);
        std::string get_name();

        std::vector<Point2D>& nodes();

        sf::Texture& loadTexture();

        void draw(sf::RenderWindow& window) override;
    };
};

#endif // OBJ_2D_H