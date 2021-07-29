#include "manager.hpp"

using namespace ard;

Manager::Manager(double screen_width, double screen_height, double world_length, double world_height, std::string game_name) :
    window_(sf::VideoMode(screen_width, screen_height), game_name),
    world_(world_length, world_height),
    camera_(world_, { 4, 3 }),
    menu_(camera_)
{}

void Manager::set_world_length(double length)
{
    world_.set_length(length);
}

void Manager::set_world_width(double width)
{
    world_.set_width(width);
}

void Manager::set_world_size(double size)
{
    world_.set_length(size);
    world_.set_width(size);
}

void Manager::set_window_size(double length, double height)
{
    window_.setSize({ unsigned int(length), unsigned int(height) });
}

void Manager::set_sky_texture(std::string sky)
{
    world_.set_sky_texture(sky);
}

void Manager::set_floor_texture(std::string floor)
{
    world_.set_floor_texture(floor);
}

void Manager::set_sky_texture(sf::Texture sky)
{
    world_.set_sky_texture(sky);
}

void Manager::set_floor_texture(sf::Texture floor)
{
    world_.set_floor_texture(floor);
}

void Manager::clear_objects()
{
    world_.clear_objects();
}

bool Manager::add_object2D(Object2D& object, std::string name)
{
    return world_.add_object2D(object, name);
}

void Manager::run()
{
    auto previous_time = std::chrono::system_clock::now();
    auto current_time  = std::chrono::system_clock::now();

    while (window_.isOpen())
    {
        current_time = std::chrono::system_clock::now();
        std::chrono::duration <double> elapsed_time = current_time - previous_time;
        previous_time = current_time;

        double d_elapsed_time = elapsed_time.count();

        std::string title = "Ardua Shooter (" + std::to_string(double(1 / d_elapsed_time)) + " fps)";
        window_.setTitle(title);

        sf::Event event;
        while (window_.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window_.close();
        }

        window_.clear();

        if (!menu_.is_paused())
        {
            camera_.update_distances(world_);
            camera_.draw_camera_view(window_);
            world_.draw(window_);
            camera_.draw(window_);

            if (!camera_.keyboard_control(d_elapsed_time, window_))
                menu_.set_pause();
        }
        else
            menu_.draw(window_);
        
        window_.display();
    }
}