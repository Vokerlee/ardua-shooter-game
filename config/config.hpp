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

    const double SCREEN_PIX_WIDTH  = SCREEN_WIDTH  * SCALE;
    const double SCREEN_PIX_HEIGHT = SCREEN_HEIGHT * SCALE;

    // WORLD  
    const double WORLD_SIZE = 6;  // size of the world in SCALE (length and width)
    
    // CAMERA
    const double COLLISION_DISTANCE = 0.1;

    // CAMERA
    const int RADIUS_CAMERA = SCALE / 10;
    const int CONVEX_NUMBER = 100;

    // OBJECTS_2D
    const int CIRCLE_CONVEX_NUMBER = 30;
    const int DISTANCES_SEGMENTS   = SCREEN_WIDTH * SCALE;

// TEXTURES 

    const std::string WALL_TEXTURE  = "textures/wall_tree.jpg";

    const std::string SKY_TEXTURE   = "textures/sky.jpeg";
    const std::string FLOOR_TEXTURE = "textures/floor.jpg";

// COLOURS

    // BACKGROUND
    const sf::Color OUTLINE_BACK_COLOR = { 255, 255, 255, 255 };
    const sf::Color FILL_BACK_COLOR    = { 255, 255, 255, 255 };
    const int OUTLINE_BACK_THICKNESS   = 5;

    // OBJECTS_2D
    const sf::Color OUTLINE_COLOR = { 0, 0, 0, 255 };
    const sf::Color FILL_COLOR    = { 14, 174, 174, 255 };
    const int OUTLINE_THICKNESS   = 2;

    // CAMERA
    const int OUTLINE_CAMERA_THICKNESS   = 1;
    const sf::Color OUTLINE_CAMERA_COLOR = { 0, 0, 0, 255 };
    const sf::Color FILL_CAMERA_COLOR    = { 255, 67, 67, 255 };
    const sf::Color FILED_OF_VEW_COLOR   = { 255, 67, 67, 0 };

};

#endif // CONFIG_H
