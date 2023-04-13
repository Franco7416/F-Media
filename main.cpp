#include <iostream>
#include <unistd.h>
#include "config.hpp"
#include "screen.hpp"
#include "col.hpp"
#include "rect.hpp"
#include "line.hpp"
#include "tri.hpp"
#include "quad.hpp"
#include "px.hpp"
#include "sprite.hpp"
using namespace FM;
int main()
{
    F_MEDIA_INIT;
    Screen s;
    Tri t(vec2(136, 192), vec2(188, 144), vec2(100, 20), true);
    s.add(t, col(Colors::Bright_Blue));
    /*Sprite spr;
    spr.s = {
        Px(vec2(0, 0), col(Colors::White), false),
        Px(vec2(0, 1), col(Colors::Black), true),
        Px(vec2(0, 2), col(Colors::White), false),

        Px(vec2(1, 0), col(Colors::Black), true),
        Px(vec2(1, 1), col(Colors::Black), true),
        Px(vec2(1, 2), col(Colors::Black), true),

        Px(vec2(2, 0), col(Colors::White), false),
        Px(vec2(2, 1), col(Colors::White), false),
        Px(vec2(2, 2), col(Colors::White), false),
    };
    s.add(spr, vec2(0, 5));*/
    s.draw();
    return 0;
}