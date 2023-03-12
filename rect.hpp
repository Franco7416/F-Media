#ifndef F_MEDIA_FIG_RECT_HPP
#define F_MEDIA_FIG_RECT_HPP
#include "vec2.hpp"
namespace Fig
{
    class Rect
    {
    public:
        vec2 pos;
        float w = 0.0F;
        float h = 0.0F;

        Rect() {}
        Rect(vec2 pos, float w, float h)
        {
            this->pos = pos;
            this->w = w;
            this->h = h;
        }

        void operator=(Fig::Rect a)
        {
            this->pos = a.pos;
            this->w = a.w;
            this->h = a.h;
        }
    };
};
#endif