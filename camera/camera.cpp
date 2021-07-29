#include "camera.hpp"

using namespace ard;

Camera::Camera(World& world, Point2D position, double direction, double field_of_view, double depth, double walk_speed, double view_speed) :
    world_(world),
    Object2D(position),
    direction_(direction),
    field_of_view_(field_of_view),
    depth_(depth),
    walk_speed_(walk_speed),
    view_speed_(view_speed)
{}

void Camera::update_distances(World& world)
{
    distances_.clear();
    std::string obj_name;

    for (int i = 0; i < 2 * field_of_view_ / PI * DISTANCES_SEGMENTS; i++)
    {
        // Left and right angles respectively to set direction
        double left  = direction_ - field_of_view_ / 2;
        double right = direction_ + field_of_view_ / 2;

        double direction = left + (double(i) / DISTANCES_SEGMENTS) * field_of_view_;
        double progress  = 0;

        // The end of radius vector (from player)
        Point2D near_cross = { x() + depth_ * cos(direction), y() + depth_ * sin(direction) };

        // Radius vector
        std::pair<Point2D, Point2D> radius_vector = { position(), near_cross };

        Point2D cross_point;
        
        double len = 0;

        for (auto object : world.objects())
        {
            if (object.first == get_name() || object.second.nodes().size() <= 1) // if the object is a line or a player
                continue;

            progress = 0;

            // The side of object
            std::pair<Point2D, Point2D> object_side = { object.second.position() + object.second.nodes().front(), object.second.position() + object.second.nodes().back() };
            
            for (int k = 0; k < object.second.nodes().size(); k++)
            {
                if (vector_crossing(radius_vector, object_side, cross_point))
                {
                    if ((near_cross - position()).abs() > (cross_point - position()).abs())
                    {
                        near_cross = cross_point;
                        obj_name = object.second.get_name();
                        len = (object_side.second - near_cross).abs();

                        // For collision detection
                        double collision_dist = (near_cross - position()).abs();

                        if (COLLISION_DISTANCE >= collision_dist)
                        {
                            collision_info new_collision;

                            new_collision.distance        = collision_dist;
                            new_collision.edge            = object_side;
                            new_collision.collision_point = near_cross;

                            collisions_.push_back(new_collision);
                        }
                    }
                }
                else
                    progress += (object_side.second - object_side.first).abs();

                if (k + 1 < object.second.nodes().size())
                    object_side = { object.second.position() + object.second.nodes()[k], object.second.position() + object.second.nodes()[k + 1] };
            }
        }

        distances_.push_back({ (position() - near_cross).abs(), len, obj_name });
    }

    check_collisions();
}

void Camera::check_collisions()
{
    int n_ñollisions = collisions_.size();

    if (b_collision_)
    {
        for (int i = n_ñollisions - 1; i >= 0; i--)
        {
            Point2D vector = collisions_[i].edge.first - collisions_[i].edge.second;
            Point2D normal_vector = { -vector.y, vector.x };

            Point2D shift_vector = normal_vector.normalize() * COLLISION_DISTANCE;
            Point2D result_position = collisions_[i].collision_point + shift_vector;

            set_position(result_position);
            collisions_.pop_back();
        }
    }
}

void Camera::draw(sf::RenderWindow& window)
{
    if (distances_.size() == 0)
        update_distances(world_);

    // Player's position rendering (on minimap)
    sf::CircleShape circle;
    circle.setRadius(RADIUS_CAMERA);
    circle.setOutlineColor(OUTLINE_CAMERA_COLOR);
    circle.setFillColor(FILL_CAMERA_COLOR);
    circle.setOutlineThickness(OUTLINE_CAMERA_THICKNESS);
    circle.setPosition(x() * SCALE - RADIUS_CAMERA, y() * SCALE - RADIUS_CAMERA);

    double left  = direction_ - field_of_view_ / 2;
    double right = direction_ + field_of_view_ / 2;

    sf::ConvexShape triangle;
    triangle.setPointCount(CONVEX_NUMBER + 2);
    triangle.setPoint(0, sf::Vector2f(0, 0));

    for (int i = 0; i <= CONVEX_NUMBER; i++)
    {
        float x = distances_[int(i * DISTANCES_SEGMENTS / CONVEX_NUMBER)].distance * cos(left + (right - left) * i / CONVEX_NUMBER) * SCALE;
        float y = distances_[int(i * DISTANCES_SEGMENTS / CONVEX_NUMBER)].distance * sin(left + (right - left) * i / CONVEX_NUMBER) * SCALE;
        triangle.setPoint(i + 1, sf::Vector2f(x, y));
    }

    triangle.setOutlineColor(OUTLINE_CAMERA_COLOR);
    triangle.setFillColor(FILED_OF_VEW_COLOR);
    triangle.setOutlineThickness(OUTLINE_CAMERA_THICKNESS);
    triangle.setPosition(x() * SCALE, y() * SCALE);

    window.draw(triangle);
    window.draw(circle);
}

std::pair<double, double> ard::height(double distance)
{
    std::pair<double, double> h = { 0, 0 };
    h.first  = (1 - 1 / distance) * SCREEN_PIX_HEIGHT / 2;
    h.second = (1 + 1 / distance) * SCREEN_PIX_HEIGHT / 2;

    return h;
}

void Camera::draw_camera_view(sf::RenderWindow& window)
{
    if (distances_.size() == 0)
        update_distances(world_);

    // Sky and floor
    if (b_textures_)
    {
        sf::Sprite sprite_sky;
        sprite_sky.setTexture(world_.sky_texture());
        sprite_sky.setTextureRect(sf::IntRect(direction_ * SCREEN_PIX_WIDTH / 2, 0, SCREEN_PIX_WIDTH, SCREEN_PIX_HEIGHT));
        sprite_sky.setPosition(sf::Vector2f(0, 0));

        sf::Sprite sprite_floor;
        sprite_floor.setTexture(world_.floor_texture());
        sprite_floor.setTextureRect(sf::IntRect(0, 0, SCREEN_PIX_WIDTH, SCREEN_PIX_HEIGHT));
        sprite_floor.setPosition(sf::Vector2f(0, SCREEN_PIX_HEIGHT / 2));
        sprite_floor.scale(1, 1. / 2);
 
        window.draw(sprite_sky);
        window.draw(sprite_floor);
    }

    // All other objects
    for (int i = 0; i < DISTANCES_SEGMENTS - 1; i++)
    {
        sf::ConvexShape polygon;
        polygon.setPointCount(4);

        std::pair<double, double> height_before = height(distances_[i].distance);
        std::pair<double, double> height_now    = height(distances_[i + 1].distance);

        int prev_h1 = height_before.first;
        int prev_h2 = height_before.second;
        int h1      = height_now.first;
        int h2      = height_now.second;

        polygon.setPoint(0, sf::Vector2f(0, h1));
        polygon.setPoint(1, sf::Vector2f(0, h2));
        polygon.setPoint(2, sf::Vector2f(SCREEN_PIX_WIDTH / DISTANCES_SEGMENTS, h2));
        polygon.setPoint(3, sf::Vector2f(SCREEN_PIX_WIDTH / DISTANCES_SEGMENTS, h1));

        int alpha = 255 * (1 - distances_[i].distance / depth_);

        if (alpha > 255)
            alpha = 255;
        else if (alpha < 0)
            alpha = 0;

        if (!b_textures_)
            polygon.setFillColor({ 255, 174, 174, static_cast<sf::Uint8>(alpha) });
        else
            polygon.setFillColor({ 255, 174, 174, 255 });

        polygon.setOutlineThickness(0);
        polygon.setPosition(SCREEN_PIX_WIDTH * i / DISTANCES_SEGMENTS, 0);

        if (abs(distances_[i].distance - depth_) > 0.001)
            window.draw(polygon);

        double scaleFactor = double(h2 - h1) / SCREEN_PIX_HEIGHT;
        sf::Sprite sprite;

        if (distances_[i].object != "" && b_textures_)
        {
            sprite.setTexture(world_[distances_[i].object].load_texture());
            sprite.setTextureRect(sf::IntRect(distances_[i].progress * SCREEN_PIX_WIDTH, 0, SCREEN_PIX_WIDTH / DISTANCES_SEGMENTS, SCREEN_PIX_HEIGHT));
            sprite.setPosition(sf::Vector2f(SCREEN_PIX_WIDTH * i / DISTANCES_SEGMENTS, SCREEN_PIX_HEIGHT / 2 - (h2 - h1) / 2));
            sprite.scale(1, scaleFactor);
            sprite.setColor({ 255, 255, 255, static_cast<sf::Uint8>(alpha) });
            window.draw(sprite);
        }
    }
}

bool Camera::keyboard_control(double elapsed_time, sf::RenderWindow& window)
{
    double dx(0);
    double dy(0);

    // Left and right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        dx +=  sin(direction_) * walk_speed_ * elapsed_time;
        dy += -cos(direction_) * walk_speed_ * elapsed_time;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        dx += -sin(direction_) * walk_speed_ * elapsed_time;
        dy +=  cos(direction_) * walk_speed_ * elapsed_time;
    }

    // Forward and backward
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        dx += cos(direction_) * walk_speed_ * elapsed_time;
        dy += sin(direction_) * walk_speed_ * elapsed_time;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        dx += -cos(direction_) * walk_speed_ * elapsed_time;
        dy += -sin(direction_) * walk_speed_ * elapsed_time;
    }

    // Escape
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        return false;
    }

    // Mouse
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        // for the future
    }

    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);

    if (mouse_pos.x != local_mouse_position_.x)
    {
        double difference     = mouse_pos.x - local_mouse_position_.x;
        local_mouse_position_ = mouse_pos;
        direction_ += view_speed_ * difference;
    }

    shift_precise({ dx, dy });

    return true;
}

void Camera::shift_precise(Point2D vector)
{
    shift(vector);
}

bool Camera::is_smooth()
{
    return b_smooth_;
}

bool Camera::is_collision()
{
    return b_collision_;
}

bool Camera::is_textures()
{
    return b_textures_;
}

void Camera::switch_collision()
{
    b_collision_ = !b_collision_;
}

void Camera::switch_textures()
{
    b_textures_ = !b_textures_;
}

void Camera::switch_smooth()
{
   b_smooth_ = !b_smooth_;
}

void Camera::set_collision(bool value)
{
    b_collision_ = value;
}

void Camera::set_textures(bool value)
{
    b_textures_ = value;
}

void Camera::set_smooth(bool value)
{
    b_smooth_ = value;
}