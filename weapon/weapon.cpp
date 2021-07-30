#include "weapon.hpp"

using namespace ard;

Weapon::Weapon(int amount) :
    amount_(amount)
{
    choose_weapon("pistols");
}

Weapon::Weapon(const Weapon& weapon)
{
    this->amount_         = weapon.amount_;
    this->speed_          = weapon.speed_;
    this->weapon_sprite_  = weapon.weapon_sprite_;
    this->weapon_texture_ = weapon.weapon_texture_;
    this->aim_texture_    = weapon.aim_texture_;
    this->aim_sprite_     = weapon.aim_sprite_;

    weapon_sprite_.setTexture(weapon_texture_);
    weapon_sprite_.setPosition(sf::Vector2f(SCREEN_PIX_WIDTH - weapon_sprite_.getTextureRect().width, SCREEN_PIX_HEIGHT - weapon_sprite_.getTextureRect().height));
}

void Weapon::choose_weapon(std::string weapon_name)
{
    if (weapon_name == "pistols")
    {
        weapon_texture_.loadFromFile(PISTOLS_TEXTURE);
        aim_texture_.loadFromFile(AIM_TEXTURE);

        speed_ = 1;
        aim_sprite_.scale(.1, .1);
    }
}

bool Weapon::fire()
{
    if (amount_ > 0)
    {
        --amount_;
        return true;
    }

    return false;
}

double Weapon::speed() const
{
    return speed_;
}

void Weapon::draw(sf::RenderWindow& window)
{
    weapon_sprite_.setTexture(weapon_texture_);
    weapon_sprite_.setPosition(sf::Vector2f(SCREEN_PIX_WIDTH - weapon_sprite_.getTextureRect().width, SCREEN_PIX_HEIGHT - weapon_sprite_.getTextureRect().height));
    window.draw(weapon_sprite_);

    aim_sprite_.setTexture(aim_texture_);
    aim_sprite_.setPosition(sf::Vector2f(SCREEN_PIX_WIDTH / 2 - aim_sprite_.getTextureRect().width / 27, SCREEN_PIX_HEIGHT / 2 - aim_sprite_.getTextureRect().height / 27));
    window.draw(aim_sprite_);
}