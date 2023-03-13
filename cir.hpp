#ifndef F_MEDIA_FIG_CIR_HPP
#define F_MEDIA_FIG_CIR_HPP
#include "vec2.hpp"
namespace Fig
{
    class Cir
    {
    public:
        vec2 pos;
        float r = 0.0F;

        Cir() {}
        Cir(vec2 pos, float r)
        {
            this->pos = pos;
            this->r = r;
        }

        void operator=(Fig::Cir a)
        {
            this->pos = a.pos;
            this->r = a.r;
        }
    };
};
#endif