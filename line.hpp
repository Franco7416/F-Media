#ifndef F_MEDIA_LINE_HPP
#define F_MEDIA_LINE_HPP
#include <cmath>
#include "vec2.hpp"
#include "vector"
using namespace FM;
namespace FM
{
    class line
    {
    public:
        FM::vec2 a;
        FM::vec2 b;

        line() {}
        line(FM::vec2 a, FM::vec2 b)
        {
            this->a = a;
            this->b = b;
        }

        void operator=(FM::line a)
        {
            this->a = a.a;
            this->b = a.b;
        }

        std::vector<FM::vec2> gen()
        {

            std::vector<FM::vec2> l;

            l.push_back(FM::vec2(this->a.x, this->a.y));
            float A = this->b.x - this->a.x;
            float B = this->b.y - this->a.y;
            float m;

            if (abs(A) > abs(B))
                m = abs(A);
            else
                m = abs(B);
            A /= m;
            B /= m;

            float a = this->a.x;
            float b = this->a.y;

            for (int i = 0; i < m; i++)
            {
                a += A;
                b += B;
                FM::vec2 v(a, b);
                l.push_back(v);
            }

            for (int i = 0; i < l.size(); i++)
            {
                l[i].x = std::round(l[i].x);
                l[i].y = std::round(l[i].y);
            }
            return l;
        }
    };

    vec2 line_intersection(line a, line b)
    {
        std::vector<vec2> A = a.gen();
        std::vector<vec2> B = b.gen();

        vec2 o;

        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < B.size(); j++)
            {
                if (A[i] == B[j])
                {
                    o = A[i];
                }
            }
        }

        return o;
    }
};
#endif