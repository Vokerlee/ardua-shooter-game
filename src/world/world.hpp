#ifndef WORLD_H
#define WORLD_H

#include <map>
#include "objects2D/object2D.hpp"

namespace ard
{
    class World : virtual public Drawable
    {
    private:
        std::map<std::string, Object2D&> map_objects_;

        double length_ = 0;
        double width_  = 0;

        sf::Sprite sky_sprite_;
        sf::Sprite floor_sprite_;

        sf::Texture sky_texture_;
        sf::Texture floor_texture_;

        bool sky_texture_loaded_   = false;
        bool floor_texture_loaded_ = false;

    public:
        World(double length = WORLD_SIZE, double width = WORLD_SIZE, std::string sky_texture = SKY_TEXTURE, std::string floor_texture = FLOOR_TEXTURE);

        bool add_object2D(Object2D& object, std::string name);
        const std::map<std::string, Object2D&>& objects() const;

        Object2D& find_object2D(std::string name);
        bool remove_object2D(std::string name);
        void clear_objects();
        Object2D& operator[](std::string name);

        void set_length(double length);
        void set_width(double width);
        
        double length() const;
        double width()  const;

        void draw(sf::RenderWindow& window) override;

        sf::Sprite& sky_sprite();
        sf::Sprite& floor_sprite();

        sf::Texture& sky_texture();
        sf::Texture& floor_texture();

        void set_sky_texture(std::string sky);
        void set_floor_texture(std::string floor);

        void set_sky_texture(sf::Texture sky);
        void set_floor_texture(sf::Texture floor);
    };
};

#endif // WORLD_H