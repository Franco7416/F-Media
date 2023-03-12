#include <iostream>
#include "fmediaconfig.h"
#include "screen.hpp"
#include "vec2.hpp"
#include "line.hpp"
#include "tri.hpp"
#include "rect.hpp"
int main()
{
    Screen s;
    /*Fig::Tri t(vec2(2, 2), vec2(70, 80), vec2(30, 60));
    s.add(t);*/

    s.draw();
    return 0;
}