#ifndef F_MEDIA_VEC2_HPP
#define F_MEDIA_VEC2_HPP
#include <cmath>
namespace FM
{
    class vec2
    {
    public:
        float x = 0.0F;
        float y = 0.0F;

        vec2() {}
        vec2(float x, float y)
        {
            this->x = x;
            this->y = y;
        }

        void operator=(FM::vec2 a)
        {
            this->x = a.x;
            this->y = a.y;
        }

        float mag()
        {
            return sqrt(pow(this->x, 2) + pow(this->y, 2));
        }

        bool operator==(vec2 b)
        {
            if (this->x == b.x && this->y == b.y)
                return true;
            return false;
        }
    };
};
#endif