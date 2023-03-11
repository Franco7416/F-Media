#include "line.hpp"
#include "vec2.hpp"
#include "screen.hpp"
#include <iostream>
int main()
{
    Screen s;
    line l(vec2(0, 0), vec2(31, 31));
    s.add(l.gen());
    s.draw();
    return 0;
}