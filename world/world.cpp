#include "world.hpp"

using namespace ard;

World::World(double length, double width, std::string sky_texture, std::string floor_texture) :
    length_(length),
    width_(width),
    s_sky_texture_(sky_texture),
    s_floor_texture_(floor_texture)
{}

bool World::add_object2D(Object2D& object, std::string name)
{
    object.set_name(name);
    return map_objects_.insert({ name, object }).second;
}

const std::map<std::string, Object2D&>& World::objects()
{
    return map_objects_;
}

Object2D& World::find_object2D(std::string name)
{
    return map_objects_.at(name);
}

bool World::remove_object2D(std::string name)
{
    return map_objects_.erase(name) > 0;
}

Object2D& World::operator[](std::string name)
{
    return find_object2D(name);
}

double World::width()
{
    return width_;
}

double World::length()
{
    return length_;
}

void World::draw(sf::RenderWindow& window)
{
    sf::ConvexShape background;

    // Polygons
    background.setPointCount(4);
    background.setPoint(0, sf::Vector2f(0, 0));
    background.setPoint(1, sf::Vector2f(length_ * SCALE, 0));
    background.setPoint(2, sf::Vector2f(length_  * SCALE, width_ * SCALE));
    background.setPoint(3, sf::Vector2f(0, width_ * SCALE));

    // World appearance
    background.setOutlineColor(OUTLINE_BACK_COLOR);
    background.setFillColor(FILL_BACK_COLOR);
    background.setOutlineThickness(OUTLINE_BACK_THICKNESS);
    background.setPosition(0, 0);

    window.draw(background);

    for (auto object : map_objects_)
        object.second.draw(window);
}

sf::Texture& World::sky_texture()
{
    if (sky_texture_loaded_)
        return sky_texture_;

    if (sky_texture_.loadFromFile(s_sky_texture_))
        sky_texture_loaded_ = true;

    sky_texture_.setRepeated(true);

    return sky_texture_;
}

sf::Texture& World::floor_texture()
{
    if (floor_texture_loaded_)
        return floor_texture_;

    if (floor_texture_.loadFromFile(s_floor_texture_))
        floor_texture_loaded_ = true;

    floor_texture_.setRepeated(true);

    return floor_texture_;
}