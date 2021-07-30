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

        sf::Sprite  weapon_sprite_;
        sf::Sprite  aim_sprite_;   

        double speed_  = 1;
        int    amount_ = 0;

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