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
// ABOUT-INFO: URL ADDRESS

    const std::string GAME_NAME = "Ardua Shooter";
    const std::string ABOUT_INFO_URL_ADDR = "https://github.com/Vokerlee/ArduaShooter";

// MATH VALUES

    const double PI = 3.1415926535897932384626433832795;

// SIZES & VELOCITIES 

    const double SCALE = 50;  // pixels per unit

    // WINDOW
    const double SCREEN_RATIO       = 16. / 9.;
    const double SCREEN_WIDTH       = 25.6;                         // width  in SCALE // 25.6 * 50 = 1280
    const double SCREEN_HEIGHT      = SCREEN_WIDTH / SCREEN_RATIO;  // height in SCALE // 14.4 * 50 = 720

    const double SCREEN_PIX_WIDTH   = SCREEN_WIDTH  * SCALE;
    const double SCREEN_PIX_HEIGHT  = SCREEN_HEIGHT * SCALE;

    // WORLD  
    const double WORLD_SIZE         = 6;  // size of the world in SCALE (length and width)
    
    // CAMERA
    const double COLLISION_DISTANCE = 0.1;
    const double COLLISION_AREA     = 1;
    const double FIELD_OF_VIEW      = PI / 2;
    const double DEPTH              = 11;

    const double RADIUS_CAMERA      = SCALE / 10;
    const int CONVEX_NUMBER         = 100;

    const double WALK_SPEED         = 1.5;
    const double VIEW_SPEED         = 0.01;

    // OBJECTS_2D
    const int CIRCLE_CONVEX_NUMBER  = 30;
    const int DISTANCES_SEGMENTS    = SCREEN_WIDTH * SCALE;

// WEAPONS

    const int BULLET_AMOUNT_DEFAULT = 1111111;

    const double PISTOLS_FREQUENCY  = 2.5;

// TEXTURES 

    // OBJECTS
    const std::string WALL_TEXTURE               = "textures/wall_tree.jpg";

    const std::string SKY_TEXTURE                = "textures/sky.jpeg";
    const std::string FLOOR_TEXTURE              = "textures/floor.jpg";

    // BUTTONS
    const std::string PLAYGAME_PRESSED_TEXTURE   = "textures/buttons/play_game_selected.jpg";
    const std::string SETTINGS_PRESSED_TEXTURE   = "textures/buttons/settings_selected.jpg";
    const std::string ABOUT_PRESSED_TEXTURE      = "textures/buttons/about_selected.jpg";
    const std::string QUIT_PRESSED_TEXTURE       = "textures/buttons/quit_selected.jpg";

    const std::string PLAYGAME_TEXTURE           = "textures/buttons/play_game.jpg";
    const std::string SETTINGS_TEXTURE           = "textures/buttons/settings.jpg";
    const std::string ABOUT_TEXTURE              = "textures/buttons/about.jpg";
    const std::string QUIT_TEXTURE               = "textures/buttons/quit.jpg";

    const std::string TEXTURING_SELECT           = "textures/buttons/texturing.jpg";
    const std::string SMOOTHING_SELECT           = "textures/buttons/smoothing.jpg";
    const std::string COLLISION_SELECT           = "textures/buttons/collision.jpg";

    const std::string TEXTURING_SELECT_S         = "textures/buttons/texturing_selected.jpg";
    const std::string SMOOTHING_SELECT_S         = "textures/buttons/smoothing_selected.jpg";
    const std::string COLLISION_SELECT_S         = "textures/buttons/collision_selected.jpg";

    // WEAPONS
    const std::string PISTOLS_TEXTURE            = "textures/weapons/pistols.png"; // "pistols"
    const std::string FIRE_PISTOLS_TEXTURE_RIGHT = "textures/weapons/fire_pistols_right.png";
    const std::string FIRE_PISTOLS_TEXTURE_LEFT  = "textures/weapons/fire_pistols_left.png";
    const std::string AIM_TEXTURE                = "textures/weapons/aim.png";

// COLOURS

    // BACKGROUND
    const sf::Color OUTLINE_BACK_COLOR   = { 255, 255, 255, 255 };
    const sf::Color FILL_BACK_COLOR      = { 255, 255, 255, 255 };
    const int OUTLINE_BACK_THICKNESS     = 5;

    // OBJECTS_2D
    const sf::Color OUTLINE_COLOR        = { 0, 0, 0, 255 };
    const sf::Color FILL_COLOR           = { 14, 174, 174, 255 };
    const int OUTLINE_THICKNESS          = 2;

    // CAMERA
    const int OUTLINE_CAMERA_THICKNESS   = 1;
    const sf::Color OUTLINE_CAMERA_COLOR = { 0, 0, 0, 255 };
    const sf::Color FILL_CAMERA_COLOR    = { 255, 67, 67, 255 };
    const sf::Color FILED_OF_VEW_COLOR   = { 255, 67, 67, 0 };

};

#endif // CONFIG_H