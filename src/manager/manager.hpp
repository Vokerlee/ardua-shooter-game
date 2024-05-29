#ifndef MANAGER_H
#define MANAGER_H

#include "objects2D/circle2D.hpp"
#include "objects2D/polygon2D.hpp"
#include "world/world.hpp"
#include "camera/camera.hpp"
#include "menu/menu.hpp"
#include "config/config.hpp"

namespace ard
{
    class Manager
    {
        sf::RenderWindow window_;

        World world_;
        Camera camera_;
        Menu menu_;

    public:
        Manager(double screen_width = SCREEN_PIX_WIDTH, double screen_height = SCREEN_PIX_HEIGHT, 
                double world_length = WORLD_SIZE,       double world_height  = WORLD_SIZE, std::string game_name = GAME_NAME);

        void set_world_length(double length);
        void set_world_width(double width);
        void set_world_size(double size);

        void set_window_size(double length, double height);

        void set_sky_texture(std::string sky);
        void set_floor_texture(std::string floor);

        void set_sky_texture(sf::Texture sky);
        void set_floor_texture(sf::Texture floor);

        void clear_objects();
        bool add_object2D(Object2D& object, std::string name);

        void run();
    };
};


#endif // MANAGER_H