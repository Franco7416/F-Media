#ifndef F_MEDIA_PX_HPP
#define F_MEDIA_PX_HPP
#include "vec2.hpp"
#include "col.hpp"
namespace FM
{
    class Px
    {
    public:
        vec2 pos;
        col c;
        bool is_t = false;

        Px() {}

        Px(vec2 pos, col c, bool is_t = false)
        {
            this->pos = pos;
            this->c = c;
            this->is_t = is_t;
        }

        void operator=(Px b)
        {
            this->pos = b.pos;
            this->c = b.c;
        }
    };
};
#endif