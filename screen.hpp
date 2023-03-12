#ifndef F_MEDIA_SCREEN_HPP
#define F_MEDIA_SCREEN_HPP
#include "fmediaconfig.h"
#include <cmath>
#include <vector>
#include "vec2.hpp"
#include <iostream>
#include <vector>
#include "rect.hpp"
#include "line.hpp"
#include "tri.hpp"
class Screen
{
public:
    Screen()
    {
        std::cout << "\t ____                                                _     _                 _____           __  __              _   _                 \n\t|  _ \\    ___   __      __   ___   _ __    ___    __| |   | |__    _   _    |  ___|         |  \\/  |   ___    __| | (_)   __ _ \n\t| |_) |  / _ \\  \\ \\ /\\ / /  / _ \\ | '__|  / _ \\  / _` |   | '_ \\  | | | |   | |_     _____  | |\\/| |  / _ \\  / _` | | |  / _` |\n\t|  __/  | (_) |  \\ V  V /  |  __/ | |    |  __/ | (_| |   | |_) | | |_| |   |  _|   |_____| | |  | | |  __/ | (_| | | | | (_| |\n\t|_|      \\___/    \\_/\\_/    \\___| |_|     \\___|  \\__,_|   |_.__/   \\__, |   |_|             |_|  |_|  \\___|  \\__,_| |_|  \\__,_|\n\t\t\t\t\t\t\t\t\t   |___/\n\n";
    }

    bool m[SCREEN_HEIGHT][SCREEN_WIDTH] = {false};

    void draw()
    {
        std::cout << "#";
        for (int i = 0; i < SCREEN_WIDTH; i++)
            std::cout << "-";
        std::cout << "#\n";

        for (int i = 0; i < SCREEN_HEIGHT; i++)
        {
            std::cout << "|";
            for (int j = 0; j < SCREEN_WIDTH; j++)
            {
                if (this->m[i][j])
                    std::cout << "Ñ";
                else
                    std::cout << " ";
            }
            std::cout << "|\n";
        }

        std::cout << "O";
        for (int i = 0; i < SCREEN_WIDTH; i++)
            std::cout << "-";
        std::cout << "#";
    }

    void add(vec2 a, bool v = true)
    {
        this->m[SCREEN_HEIGHT - int(std::round(a.y)) - 1][int(std::round(a.x))] = v;
    }

    void add(std::vector<vec2> a, bool v = true)
    {
        for (int i = 0; i < a.size(); i++)
        {
            this->m[SCREEN_HEIGHT - int(std::round(a[i].y)) - 1][int(std::round(a[i].x))] = v;
        }
    }

    void add(Fig::Rect a, bool v = true)
    {
        this->add(line(a.pos, vec2(a.pos.x + a.w, a.pos.y)).gen());
        this->add(line(a.pos, vec2(a.pos.x, a.pos.y + a.h)).gen());
        this->add(line(vec2(a.pos.x + a.w, a.pos.y), vec2(a.pos.x + a.w, a.pos.y + a.h)).gen());
        this->add(line(vec2(a.pos.x, a.pos.y + a.h), vec2(a.pos.x + a.w, a.pos.y + a.h)).gen());
    }

    void add(Fig::Tri t, bool v = true)
    {
        // ab   bc  ca
        this->add(line(t.a, t.b).gen());
        this->add(line(t.b, t.c).gen());
        this->add(line(t.c, t.a).gen());
    }
};
#endif