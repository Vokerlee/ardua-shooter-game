#include "object2D.hpp"

using namespace ard;

Object2D::Object2D(Point2D position, std::vector<Point2D> points, std::string texture, Point2D velocity) :
    position_(position),
    points2D_(points),
    velocity_(velocity),
    texture_name_(std::move(texture))
{}

double Object2D::x()
{
    return position_.x;
}

double Object2D::y()
{
    return position_.y;
}

const Point2D Object2D::position()
{
    return position_;
}

void Object2D::set_position(Point2D position)
{
    position_ = position;
}

void Object2D::set_position(double x, double y)
{
    position_ = { x ,y };
}

void Object2D::shift(Point2D vector)
{
    position_ += vector;
}

void Object2D::set_name(std::string name)
{
    name_ = name;
}

std::string Object2D::get_name()
{
    return name_;
}

std::vector<Point2D>& Object2D::nodes()
{
    return points2D_;
}

sf::Texture& Object2D::loadTexture()
{
    if (texture_loaded_)
        return texture_;

    if (texture_.loadFromFile(texture_name_))
        texture_loaded_ = true;

    texture_.setRepeated(true); // to duplicate the same picture in case it is smaller than screen

    return texture_;
}

void Object2D::draw(sf::RenderWindow& window)
{
    sf::ConvexShape polygon;
    polygon.setPointCount(nodes().size());

    int i = 0;
    for (auto ptr : nodes())
        polygon.setPoint(i++, sf::Vector2f(ptr.x * SCALE, ptr.y * SCALE));

    polygon.setOutlineColor(OUTLINE_COLOR);
    polygon.setFillColor(FILL_COLOR);
    polygon.setOutlineThickness(OUTLINE_THICKNESS);
    polygon.setPosition((float) (x() * SCALE), (float) (y() * SCALE));

    window.draw(polygon);
}