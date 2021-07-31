#include "weapon.hpp"

using namespace ard;

Weapon::Weapon(int amount) :
    amount_(amount),
    n_weapons_(n_weapon::ONE)
{
    choose_weapon("pistols");
}

Weapon::Weapon(const Weapon& weapon)
{
    amount_         = weapon.amount_;
    speed_          = weapon.speed_;
    weapon_sprite_  = weapon.weapon_sprite_;
    weapon_texture_ = weapon.weapon_texture_;
    aim_texture_    = weapon.aim_texture_;
    aim_sprite_     = weapon.aim_sprite_;
    fire_texture_   = weapon.fire_texture_;
    fire_sprite_    = weapon.fire_sprite_;

    n_weapons_      = weapon.n_weapons_;
    arm_state_      = weapon.arm_state_;

    weapon_sprite_.setTexture(weapon_texture_);
    weapon_sprite_.setPosition(sf::Vector2f(SCREEN_PIX_WIDTH - weapon_sprite_.getTextureRect().width, SCREEN_PIX_HEIGHT - weapon_sprite_.getTextureRect().height));
}

void Weapon::choose_weapon(std::string weapon_name)
{
    if (weapon_name == "pistols")
    {
        n_weapons_ = n_weapon::TWO;
        arm_state_ = arm::RIGHT;

        weapon_texture_.loadFromFile(PISTOLS_TEXTURE);
        aim_texture_.   loadFromFile(AIM_TEXTURE);
        fire_texture_.  loadFromFile(FIRE_PISTOLS_TEXTURE_RIGHT);

        speed_ = 1 / PISTOLS_FREQUENCY;
        aim_sprite_.scale(0.1, 0.1);
    }
}

void Weapon::switch_arm()
{
    if (arm_state_ == arm::LEFT)
    {
        fire_texture_.loadFromFile(FIRE_PISTOLS_TEXTURE_RIGHT);
        arm_state_ = arm::RIGHT;
    }
    else if (arm_state_ == arm::RIGHT)
    {
        fire_texture_.loadFromFile(FIRE_PISTOLS_TEXTURE_LEFT);
        arm_state_ = arm::LEFT;
    }
        
}

bool Weapon::fire()
{
    if (amount_ > 0 && last_fire_time_ == 0) // (last_fire_time_ = 0) is a sign to fire
    {
        last_fire_time_ = speed_;
        fire_anim_time_ = 0.1;

        fire_shift_ = 2 * SCALE;
        --amount_;

        if (n_weapons_ == n_weapon::TWO)
            switch_arm();

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
    std::chrono::duration <double> elapsed_time = std::chrono::system_clock::now().time_since_epoch();
    double diff_time = elapsed_time.count() - elapsed_time_;
    elapsed_time_    = elapsed_time.count();

    if (fire_shift_ > 0)
        fire_shift_ -= 2.6 * SCALE * diff_time;
    else
        fire_shift_ = 0;

    double breath_shift = SCALE * 0.26 * (1 + cos(3 * elapsed_time_));

    last_fire_time_ -= diff_time;  // (last_fire_time_ > 0) is a blocking shot
    if (last_fire_time_ < 0)
        last_fire_time_ = 0;

    fire_anim_time_ -= diff_time;  // while (fire_anim_time_ > 0) the fire is painted
    if (fire_anim_time_ > 0)
    {
        fire_sprite_.setTexture(fire_texture_);

        if (n_weapons_ == n_weapon::TWO)
        {
            if (arm_state_ == arm::RIGHT)
            {
                fire_sprite_.setPosition(sf::Vector2f(SCREEN_PIX_WIDTH  / 2 - SCALE * 3.6 + breath_shift / 2 + fire_shift_ / 3,
                                                      SCREEN_PIX_HEIGHT / 2 - SCALE * 0.9 + breath_shift / 2 + fire_shift_ / 3));
            }
            else if (arm_state_ == arm::LEFT)
            {
                fire_sprite_.setPosition(sf::Vector2f(SCREEN_PIX_WIDTH  / 2 - SCALE * 3.6 - breath_shift / 2 + fire_shift_ / 3,
                                                      SCREEN_PIX_HEIGHT / 2 - SCALE * 0.9 + breath_shift / 2 + fire_shift_ / 3));
            }
        }
        else
        {
            fire_sprite_.setPosition(sf::Vector2f(SCREEN_PIX_WIDTH  / 2 - SCALE * 3.6 + breath_shift / 2 + fire_shift_ / 3,
                                                  SCREEN_PIX_HEIGHT / 2 - SCALE * 0.9 + breath_shift / 2 + fire_shift_ / 3));
        }

        window.draw(fire_sprite_);
    }

    weapon_sprite_.setTexture(weapon_texture_);
    weapon_sprite_.setPosition(sf::Vector2f(SCREEN_PIX_WIDTH  - weapon_sprite_.getTextureRect().width,
                                            SCREEN_PIX_HEIGHT - weapon_sprite_.getTextureRect().height + breath_shift + fire_shift_));
    window.draw(weapon_sprite_);

    aim_sprite_.setTexture(aim_texture_);
    aim_sprite_.setPosition(sf::Vector2f(SCREEN_PIX_WIDTH / 2 - aim_sprite_.getTextureRect().width / 27, SCREEN_PIX_HEIGHT / 2 - aim_sprite_.getTextureRect().height / 27));
    window.draw(aim_sprite_);
}