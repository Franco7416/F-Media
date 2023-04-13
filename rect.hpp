#ifndef F_MEDIA_RECT_HPP
#define F_MEDIA_RECT_HPP
#include "vec2.hpp"
namespace FM
{
    class Rect
    {
    public:
        FM::vec2 pos;
        float w = 0.0F;
        float h = 0.0F;
        bool is_full = false;

        Rect() {}
        Rect(FM::vec2 pos, float w, float h, bool is_full = false)
        {
            this->pos = pos;
            this->w = w;
            this->h = h;
            this->is_full = is_full;
        }

        void operator=(FM::Rect a)
        {
            this->pos = a.pos;
            this->w = a.w;
            this->h = a.h;
            this->is_full = a.is_full;
        }
    };
};
#endif