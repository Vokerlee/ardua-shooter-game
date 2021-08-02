#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "../config/config.hpp"

namespace ard
{
    class Drawable
    {
    public:
        virtual void draw(sf::RenderWindow& window) = 0; // pure virtual func
    };
}

#endif // DRAWABLE_H