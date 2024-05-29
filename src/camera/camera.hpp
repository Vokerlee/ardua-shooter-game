#ifndef CAMERA_H
#define CAMERA_H

#include "config/config.hpp"
#include "point2D/point2D.hpp"
#include "objects2D/object2D.hpp"
#include "world/world.hpp"
#include "weapon/weapon.hpp"

namespace ard
{
    struct texture_params
    {
        double distance;
        double progress;
        std::string object;
    };

    struct collision_info
    {
        double distance;
        Point2D collision_point;
        std::pair<Point2D, Point2D> edge;
    };

    class Camera : public Object2D
    {
        World& world_;

        std::vector<texture_params> distances_;
        std::vector<collision_info> collisions_; // for each collision

        double direction_;
        double field_of_view_;
        double depth_;

        double walk_speed_;
        double view_speed_;

        sf::Vector2i local_mouse_position_;

        bool b_collision_ = true;
        bool b_textures_  = true;
        bool b_smooth_    = false;

        std::vector<Weapon> weapons_;
        int selected_weapon_ = 0;

        void shift_precise(Point2D vector);

    public:
        explicit Camera(World& world, Point2D position, double direction = 0, double field_of_view = FIELD_OF_VIEW, 
                        double depth = DEPTH, double walk_speed = WALK_SPEED, double view_speed = VIEW_SPEED);

        void update_distances(World& world);

        void draw_camera_view(sf::RenderWindow& window);
        void draw_view_field(sf::RenderWindow& window);
        void draw_camera_position(sf::RenderWindow& window);
        void draw(sf::RenderWindow& window) override;
        
        bool keyboard_control(double elapsed_time, sf::RenderWindow& window);

        bool is_smooth();
        bool is_collision();
        bool is_textures();

        void switch_collision();
        void switch_textures();
        void switch_smooth();

        void set_collision(bool value);
        void set_textures(bool value);
        void set_smooth(bool value);

        void previous_weapon();
        void next_weapon();
    };

    std::pair<double, double> height(double distance);
};

#endif // CAMERA_H