#ifndef WORLD_H
#define WORLD_H

#include <map>
#include "../objects2D/object2D.hpp"

namespace ard
{
    class World : virtual public Drawable
    {
    private:
        std::map<std::string, Object2D&> map_objects_;

        double length_ = 0;
        double width_  = 0;

        sf::Texture sky_texture_;
        sf::Texture floor_texture_;

        std::string s_sky_texture_;
        std::string s_floor_texture_;

        bool sky_texture_loaded_   = false;
        bool floor_texture_loaded_ = false;

    public:
        World(double length = WORLD_SIZE, double width = WORLD_SIZE, std::string sky_texture = SKY_TEXTURE, std::string floor_texture = FLOOR_TEXTURE);

        bool add_object2D(Object2D& object, std::string name);
        const std::map<std::string, Object2D&>& objects();

        Object2D& find_object2D(std::string name);
        bool remove_object2D(std::string name);
        Object2D& operator[](std::string name);

        double width();
        double length();

        void draw(sf::RenderWindow& window) override;

        sf::Texture& sky_texture();
        sf::Texture& floor_texture();
    };
};

#endif // WORLD_H