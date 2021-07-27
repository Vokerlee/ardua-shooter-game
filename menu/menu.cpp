#include "menu.hpp"

using namespace ard;

void Button::select()
{
    if (!selected && !pressed)
    {
        button.setTexture(pressed_texture);
        selected = true;
        button.scale({ 1.01, 1.01 });
    }
}

void Button::unselect()
{
    if (selected && !pressed)
    {
        button.setTexture(texture);
        selected = false;
        button.scale({ 1 / 1.01, 1 / 1.01 });
    }
}

void Button::press()
{
    if (!pressed)
    {
        button.setTexture(pressed_texture);
        pressed = true;
    }
    else
    {
        button.setTexture(texture);
        pressed = false;
    }
}

Menu::Menu(Camera& camera) :
    camera_(camera)
{
    buttons_.assign(7, {});

    buttons_[0].name = "play_game";
    buttons_[0].texture.loadFromFile(PLAYGAME_TEXTURE);
    buttons_[0].pressed_texture.loadFromFile(PLAYGAME_PRESSED_TEXTURE);

    buttons_[1].name = "settings";
    buttons_[1].texture.loadFromFile(SETTINGS_TEXTURE);
    buttons_[1].pressed_texture.loadFromFile(SETTINGS_PRESSED_TEXTURE);

    buttons_[2].name = "about";
    buttons_[2].texture.loadFromFile(ABOUT_TEXTURE);
    buttons_[2].pressed_texture.loadFromFile(ABOUT_PRESSED_TEXTURE);

    buttons_[3].name = "quit";
    buttons_[3].texture.loadFromFile(QUIT_TEXTURE);
    buttons_[3].pressed_texture.loadFromFile(QUIT_PRESSED_TEXTURE);

    buttons_[4].name = "texturing";
    buttons_[4].pressed_texture.loadFromFile(TEXTURING_SELECT_S);
    buttons_[4].texture.loadFromFile(TEXTURING_SELECT);

    buttons_[5].name = "smoothing";
    buttons_[5].texture.loadFromFile(SMOOTHING_SELECT);
    buttons_[5].pressed_texture.loadFromFile(SMOOTHING_SELECT_S);

    buttons_[6].name = "collision";
    buttons_[6].texture.loadFromFile(COLLISION_SELECT);
    buttons_[6].pressed_texture.loadFromFile(COLLISION_SELECT_S);

    buttons_[4].press();

    for (int i = 0; i < buttons_.size(); i++)
    {
        buttons_[i].button.setTexture(buttons_[i].texture);

        if (i < 4)
            buttons_[i].button.setPosition(SCREEN_PIX_WIDTH / 2 - 3.4 * SCALE, (1 + 3 * i) * SCALE);
        else
            buttons_[i].button.setPosition(SCREEN_PIX_WIDTH / 2 - 3.4 * SCALE, (1 + 3 * (i - 4)) * SCALE);
    }
}

void Menu::draw(sf::RenderWindow& window) 
{
    sf::ConvexShape back;

    back.setPointCount(4);

    back.setPoint(0, sf::Vector2f(0, 0));
    back.setPoint(1, sf::Vector2f(SCREEN_PIX_WIDTH, 0));
    back.setPoint(2, sf::Vector2f(SCREEN_PIX_WIDTH, SCREEN_PIX_HEIGHT));
    back.setPoint(3, sf::Vector2f(0, SCREEN_PIX_HEIGHT));
    back.setPosition({ 0, 0 });
    back.setFillColor({ 255, 255, 255 });

    window.draw(back);

    for (int i = 0; i < buttons_.size(); i++)
    {
        if (buttons_[i].button.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
        {
            buttons_[i].select();

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                buttons_[i].unselect();

                if (!b_settings_)
                {
                    if (buttons_[i].name == "play_game")
                        b_pause_ = false;

                    if (buttons_[i].name == "settings")
                        b_settings_ = true;

                    if (buttons_[i].name == "about")
                        b_about_ = true;

                    if (buttons_[i].name == "quit")
                        window.close();
                }
                else
                {
                    if (buttons_[i].name == "texturing")
                    {
                        buttons_[i].press();
                        camera_.set_textures(buttons_[i].pressed);
                    }

                    if (buttons_[i].name == "smoothing")
                    {
                        buttons_[i].press();
                        camera_.set_smooth(buttons_[i].pressed);
                    }

                    if (buttons_[i].name == "collision")
                    {
                        buttons_[i].press();
                        camera_.set_collision(buttons_[i].pressed);
                    }
                }
            }
        }
        else
            buttons_[i].unselect();

        if (!b_settings_ && !b_about_ && i < 4)
            window.draw(buttons_[i].button);
    }

    settings(window);
    about(window);
}

void Menu::about(sf::RenderWindow& window)
{
    if (!b_about_)
        return;

    std::string start = "start ";
    system((start + ABOUT_INFO_URL_ADDR).c_str());

    b_about_ = false;
}

void Menu::settings(sf::RenderWindow& window)
{
    if (!b_settings_) return;

    for (int i = 4; i < buttons_.size(); i++)
        window.draw(buttons_[i].button);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        b_settings_ = false;
}

bool Menu::is_paused()
{
    return b_pause_;
}

void Menu::set_pause()
{
    b_pause_ = true;
}

void Menu::switch_collision()
{
    camera_.switch_collision();
}

void Menu::switch_textures()
{
    camera_.switch_textures();
}

void Menu::switch_smooth()
{
    camera_.switch_smooth();
}

bool Menu::is_collision()
{
    return camera_.is_collision();
}

bool Menu::is_textures()
{
    return camera_.is_textures();
}

bool Menu::is_smooth()
{
    return camera_.is_smooth();
}