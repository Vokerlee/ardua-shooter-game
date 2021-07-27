#ifndef MENU_H
#define MENU_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>
#include <chrono>

#include "../config/config.hpp"
#include "../camera/camera.hpp"

namespace ard
{
    struct Button
    {
        sf::Sprite button;

        sf::Texture texture;
        sf::Texture pressed_texture;
        
        std::string name;

        bool selected = false;
        bool pressed  = false;

        void select();
        void unselect();
        void press();
    };

    class Menu
    {
        Camera& camera_;
        std::vector<Button> buttons_;

        double last_time_ = 0;

        bool b_pause_     = true;

        bool b_settings_  = false;
        bool b_about_     = false;

        void settings(sf::RenderWindow& window);
        void about(sf::RenderWindow& window);

    public:
        Menu(Camera& camera);

        void draw(sf::RenderWindow& window);

        bool is_paused();
        void set_pause();

        bool is_smooth();
        bool is_collision();
        bool is_textures();

        void switch_smooth();
        void switch_collision();
        void switch_textures();
    };
};


#endif // MENU_H