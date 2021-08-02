#include "object2D.hpp"

using namespace ard;

Object2D::Object2D(Point2D position, std::vector<Point2D> points, std::string texture, Point2D velocity) :
    position_(position),
    points2D_(points),
    velocity_(velocity),
    s_texture_(std::move(texture))
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

sf::Texture& Object2D::load_texture()
{
    if (texture_loaded_)
        return texture_;

    if (texture_.loadFromFile(s_texture_))
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

bool Object2D::vector_crossing(std::pair<Point2D, Point2D> vector1, std::pair<Point2D, Point2D> vector2, Point2D& point)
{
    Point2D cut1 = vector1.second - vector1.first;
    Point2D cut2 = vector2.second - vector2.first;

    double prod1 = cross(cut1, (vector2.first  - vector1.first));
    double prod2 = cross(cut1, (vector2.second - vector1.first));

    if (sign(prod1) == sign(prod2) || (prod1 == 0) || (prod2 == 0))
        return false;

    prod1 = cross(cut2, (vector1.first - vector2.first));
    prod2 = cross(cut2, (vector1.second - vector2.first));

    if (sign(prod1) == sign(prod2) || (prod1 == 0) || (prod2 == 0))
        return false;

    point.x = vector1.first.x + cut1.x * std::abs(prod1) / std::abs(prod2 - prod1);
    point.y = vector1.first.y + cut1.y * std::abs(prod1) / std::abs(prod2 - prod1);

    return true;
}