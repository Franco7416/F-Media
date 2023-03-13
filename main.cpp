#include <iostream>
#include "fmediaconfig.h"
#include "screen.hpp"
#include "vec2.hpp"
#include "line.hpp"
#include "tri.hpp"
#include "rect.hpp"
#include "cir.hpp"
#include "txt.hpp"
int main()
{
    Screen s;
    /*Fig::Cir c(vec2(100, 100), 100);
    s.add(c);
    s.draw();
    Txt a;
    a.p("hola");*/
    Fig::Rect r(vec2(100, 100), 99, 99, true);
    s.add(r);
    s.draw();
    return 0;
}