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

    // SCREEN SIZES
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;

    // TEXTURES 
    const std::string WALL_TEXTURE = "../textures/wall_tree.jpg";

    // WORLD
    const double SCALE = 50;

    // OBJECTS_2D
    const int CIRCLE_CONVEX_NUMBER = 30;

    const sf::Color OUTLINE_COLOR = { 0, 0, 0, 255 };
    const sf::Color FILL_COLOR = { 14, 174, 174, 255 };
    const int OUTLINE_THICKNESS = 2;
};

#endif // CONFIG_H
