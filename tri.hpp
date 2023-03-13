#ifndef F_MEDIA_FIG_TRI_HPP
#define F_MEDIA_FIG_TRI_HPP
#include "vec2.hpp"
namespace Fig
{
    class Tri
    {
    public:
        vec2 a;
        vec2 b;
        vec2 c;

        Tri() {}
        Tri(vec2 a, vec2 b, vec2 c)
        {
            this->a = a;
            this->b = b;
            this->c = c;
        }

        void operator=(Fig::Tri a)
        {
            this->a = a.a;
            this->b = a.b;
            this->c = a.c;
        }
    };
};
#endif