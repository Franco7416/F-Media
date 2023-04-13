#ifndef F_MEDIA_QUAD_HPP
#define F_MEDIA_QUAD_HPP
#include "vec2.hpp"
namespace FM
{
    class Quad
    {
    public:
        FM::vec2 a;
        FM::vec2 b;
        FM::vec2 c;
        FM::vec2 d;
        bool is_full = false;

        Quad() {}
        Quad(FM::vec2 a, FM::vec2 b, FM::vec2 c, FM::vec2 d, bool is_full = false)
        {
            this->a = a;
            this->b = b;
            this->c = c;
            this->d = d;
            this->is_full = is_full;
        }

        void operator=(FM::Quad a)
        {
            this->a = a.a;
            this->b = a.b;
            this->c = a.c;
            this->d = a.d;
            this->is_full = a.is_full;
        }
    };
};
#endif