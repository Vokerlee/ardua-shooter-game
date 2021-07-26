#ifndef CONFIG_H
#define CONFIG_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <map>
#include <iostream>
#include <chrono>
#include <utility>
#include <vector>
#include <cmath>

namespace ard
{
// MATH VALUES

    const double PI = 3.1415926535897932384626433832795;

// SIZES

    const double SCALE = 50;  // pixels per unit

    // WINDOW
    const double SCREEN_RATIO  = 16. / 9.;
    const double SCREEN_WIDTH  = 25.6;                         // width  in SCALE // 25.6 * 50 = 1280
    const double SCREEN_HEIGHT = SCREEN_WIDTH / SCREEN_RATIO;  // height in SCALE // 14.4 * 50 = 720

    // WORLD  
    const double WORLD_SIZE = 6;  // size of the world in SCALE (length and width)

    // OBJECTS_2D
    const int CIRCLE_CONVEX_NUMBER = 30;

// TEXTURES 

    const std::string WALL_TEXTURE  = "../textures/wall_tree.jpg";

    const std::string SKY_TEXTURE   = "../textures/sky.jpeg";
    const std::string FLOOR_TEXTURE = "../textures/floor.jpg";

// COLOURS

    // BACKGROUND
    const sf::Color OUTLINE_BACK_COLOR = { 255, 255, 255, 255 };
    const sf::Color FILL_BACK_COLOR    = { 255, 255, 255, 255 };
    const int OUTLINE_BACK_THICKNESS   = 5;

    // OBJECTS_2D
    const sf::Color OUTLINE_COLOR = { 0, 0, 0, 255 };
    const sf::Color FILL_COLOR    = { 14, 174, 174, 255 };
    const int OUTLINE_THICKNESS   = 2;

};

#endif // CONFIG_H
