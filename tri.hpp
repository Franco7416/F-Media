#ifndef F_MEDIA_TRI_HPP
#define F_MEDIA_TRI_HPP
#include <algorithm>
#include "vec2.hpp"
namespace FM
{
    class Tri
    {
    public:
        FM::vec2 a;
        FM::vec2 b;
        FM::vec2 c;
        bool is_full = false;

        Tri() {}
        Tri(FM::vec2 a, FM::vec2 b, FM::vec2 c, bool is_full = false)
        {
            this->a = a;
            this->b = b;
            this->c = c;
            this->is_full = is_full;
        }

        void operator=(FM::Tri a)
        {
            this->a = a.a;
            this->b = a.b;
            this->c = a.c;
            this->is_full = a.is_full;
        }

        float area()
        {
            return abs((((std::max(std::max(this->a.x, this->b.x), this->c.x)) - (std::min(std::min(this->a.x, this->b.x), this->c.x))) * (std::max(std::max(this->a.y, this->b.y), this->c.y) - std::min(std::min(this->a.y, this->b.y), this->c.y))) / 2.0F);
        }

        void sort_y_vec()
        {
            vec2 ty[] = {vec2(0, 0), this->a, this->b, this->c};

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (ty[j].y > ty[j + 1].y)
                    {
                        vec2 aux;
                        aux = ty[j];
                        ty[j] = ty[j + 1];
                        ty[j + 1] = aux;
                    }
                }
            }

            this->a = ty[1];
            this->b = ty[2];
            this->c = ty[3];
        }

        void sort_x_vec()
        {
            vec2 tx[] = {vec2(0, 0), this->a, this->b, this->c};

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (tx[j].x > tx[j + 1].x)
                    {
                        vec2 aux;
                        aux = tx[j];
                        tx[j] = tx[j + 1];
                        tx[j + 1] = aux;
                    }
                }
            }

            this->a = tx[1];
            this->b = tx[2];
            this->c = tx[3];
        }
    };
};
#endif