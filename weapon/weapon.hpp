#ifndef WEAPON_H
#define WEAPON_H

#include "../config/config.hpp"
#include "../config/drawable.hpp"

namespace ard
{
    class Weapon : virtual public Drawable
    {
        sf::Texture weapon_texture_;
        sf::Texture aim_texture_;
        sf::Texture fire_texture_;
        
        sf::Sprite  weapon_sprite_;
        sf::Sprite  aim_sprite_;   
        sf::Sprite  fire_sprite_;

        double fire_shift_     = 0;
        double fire_anim_time_ = 0; // the time to show the fire
        double last_fire_time_ = 0; // the time for 1 shot recharge

        double elapsed_time_;

        double speed_  = 0;
        int    amount_ = 0;

        enum class n_weapon
        {
            ONE = 1,
            TWO = 2
        } n_weapons_;

        enum class arm
        {
            LEFT  = 1,
            RIGHT = 2
        } arm_state_;

        void switch_arm();

    public:
        Weapon(int amount = BULLET_AMOUNT_DEFAULT);
        Weapon(const Weapon& weapon);

        void choose_weapon(std::string weapon_name);

        bool fire();
        double speed() const;

        void draw(sf::RenderWindow& window) override;
    };
};

#endif // WEAPON_H