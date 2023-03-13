#ifndef F_MEDIA_VEC2_HPP
#define F_MEDIA_VEC2_HPP
#include "fmediaconfig.h"
class vec2
{
public:
    float x = 0.0F;
    float y = 0.0F;
    vec2()
    {
        this->x = 0.0F;
        this->y = 0.0F;
    }
    vec2(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
    void operator=(vec2 a)
    {
        this->x = a.x;
        this->y = a.y;
    }
    vec2 operator+(vec2 b)
    {
        vec2 r;
        r.x = this->x + b.x;
        r.y = this->y + b.y;
        return r;
    }
    vec2 operator-(vec2 b)
    {
        vec2 r;
        r.x = this->x - b.x;
        r.y = this->y - b.y;
        return r;
    }
    vec2 operator*(vec2 b)
    {
        vec2 r;
        r.x = this->x * b.x;
        r.y = this->y * b.y;
        return r;
    }
    vec2 operator/(vec2 b)
    {
        vec2 r;
        r.x = this->x / b.x;
        r.y = this->y / b.y;
        return r;
    }
    void operator+=(vec2 b)
    {
        this->operator=(this->operator+(b));
    }
    void operator-=(vec2 b)
    {
        this->operator=(this->operator-(b));
    }
    void operator*=(vec2 b)
    {
        this->operator=(this->operator*(b));
    }
    void operator/=(vec2 b)
    {
        this->operator=(this->operator/(b));
    }
};
#endif