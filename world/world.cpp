#include "world.hpp"

using namespace ard;

World::World(double length, double width, std::string sky_texture, std::string floor_texture) :
    length_(length),
    width_(width)
{
    set_sky_texture(sky_texture);
    set_floor_texture(floor_texture);
}

bool World::add_object2D(Object2D& object, std::string name)
{
    object.set_name(name);
    return map_objects_.insert({ name, object }).second;
}

const std::map<std::string, Object2D&>& World::objects() const
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

void World::clear_objects()
{
    map_objects_.clear();
}

Object2D& World::operator[](std::string name)
{
    return find_object2D(name);
}

void World::set_length(double length)
{
    length_ = length;
}

void World::set_width(double width)
{
    width_ = width;
}

double World::length() const
{
    return length_;
}

double World::width() const
{
    return width_;
}

void World::draw(sf::RenderWindow& window)
{
    sf::ConvexShape background;

    // Polygon
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

sf::Sprite& World::sky_sprite()
{
    return sky_sprite_;
}

sf::Sprite& World::floor_sprite()
{
    return floor_sprite_;
}

sf::Texture& World::sky_texture()
{
    return sky_texture_;
}

sf::Texture& World::floor_texture()
{
    return floor_texture_;
}

void World::set_sky_texture(std::string sky_texture)
{
    if (sky_texture_.loadFromFile(sky_texture))
        sky_texture_loaded_ = true;

    sky_texture_.setRepeated(true);

    if (sky_texture_loaded_)
    {
        sky_sprite_.setTexture(sky_texture_);
        sky_sprite_.setPosition(sf::Vector2f(0, 0));
    }
}

void World::set_floor_texture(std::string floor_texture)
{
    if (floor_texture_.loadFromFile(floor_texture))
        floor_texture_loaded_ = true;

    floor_texture_.setRepeated(true);

    if (floor_texture_loaded_)
    {
        floor_sprite_.setTexture(floor_texture_);
        floor_sprite_.setTextureRect(sf::IntRect(0, 0, SCREEN_PIX_WIDTH, SCREEN_PIX_HEIGHT));
        floor_sprite_.setPosition(sf::Vector2f(0, SCREEN_PIX_HEIGHT / 2));
        floor_sprite_.scale(1, 1. / 2);
    }
}

void World::set_sky_texture(sf::Texture sky)
{
    sky_texture_ = sky;
    sky_texture_.setRepeated(true);
    sky_texture_loaded_ = true;

    sky_sprite_.setTexture(sky_texture_);
    sky_sprite_.setPosition(sf::Vector2f(0, 0));
}

void World::set_floor_texture(sf::Texture floor)
{
    floor_texture_ = floor;
    floor_texture_.setRepeated(true);
    floor_texture_loaded_ = true;

    sky_sprite_.setTexture(floor_texture_);
    sky_sprite_.setTextureRect(sf::IntRect(0, 0, SCREEN_PIX_WIDTH, SCREEN_PIX_HEIGHT));
    sky_sprite_.setPosition(sf::Vector2f(0, SCREEN_PIX_HEIGHT / 2));
    sky_sprite_.scale(1, 1. / 2);
}