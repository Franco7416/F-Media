#ifndef F_MEDIA_SPRITE_HPP
#define F_MEDIA_SPRITE_HPP
#include <vector>
#include "px.hpp"
namespace FM
{
    class Sprite
    {
    public:
        std::vector<Px> s;

        Sprite(){};

        void operator=(Sprite b)
        {
            this->s = b.s;
        }
    };
};
#endif