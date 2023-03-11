#ifndef F_MEDIA_LINE_HPP
#define F_MEDIA_LINE_HPP
#include "vec2.hpp"
#include <vector>
#include <cmath>
class line
{
public:
    vec2 *a;
    vec2 *b;

    line(vec2 a, vec2 b)
    {
        this->a = &a;
        this->b = &b;
    }
    void operator=(line b)
    {
        this->a = b.a;
        this->b = b.b;
    }
    std::vector<vec2> gen()
    {
        std::vector<vec2> l;
        l.push_back(vec2(this->a->x, this->a->y));
        float A = this->b->x - this->a->x;
        float B = this->b->y - this->a->y;
        float m;

        bool is_a_posi = true;
        bool is_b_posi = true;
        if (A < 0)
        {
            A *= -1;
            is_a_posi = false;
        }
        if (B < 0)
        {
            B *= -1;
            is_b_posi = false;
        }
        if (A > B)
            m = A;
        else
            m = B;
        if (!is_a_posi)
            A *= -1;
        if (!is_b_posi)
            B *= -1;
        A /= m;
        B /= m;

        float a = this->a->x;
        float b = this->a->y;

        for (int i = 0; i < m; i++)
        {
            a += A;
            b += B;
            vec2 v(a, b);
            l.push_back(v);
        }

        for (int i = 0; i < l.size(); i++)
        {
            /*l[i].x = int(l[i].x);
            l[i].y = int(l[i].y);*/
            l[i].x = std::round(l[i].x);
            l[i].y = std::round(l[i].y);
        }
        return l;
    }
};
#endif