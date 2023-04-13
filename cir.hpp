#ifndef F_MEDIA_CIR_HPP
#define F_MEDIA_CIR_HPP
#include "vec2.hpp"
namespace FM
{
    class Cir
    {
    public:
        FM::vec2 pos;
        float r = 0.0F;
        bool is_full = false;

        Cir() {}
        Cir(FM::vec2 pos, float r, bool is_full = false)
        {
            this->pos = pos;
            this->r = r;
            this->is_full = is_full;
        }

        void operator=(FM::Cir a)
        {
            this->pos = a.pos;
            this->r = a.r;
            this->is_full = a.is_full;
        }
    };
};
#endif