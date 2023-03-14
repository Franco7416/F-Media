#ifndef F_MEDIA_SCREEN_HPP
#define F_MEDIA_SCREEN_HPP
#include "fmediaconfig.h"
#include "vec2.hpp"
#include "line.hpp"
#include "rect.hpp"
#include "tri.hpp"
#include "cir.hpp"
#include "txt.hpp"
#include <iostream>
#include <vector>
#include <cmath>
class Screen
{
public:
    Screen()
    {
        std::cout << "\t ____                                                _     _                 _____           __  __              _   _                 \n\t|  _ \\    ___   __      __   ___   _ __    ___    __| |   | |__    _   _    |  ___|         |  \\/  |   ___    __| | (_)   __ _ \n\t| |_) |  / _ \\  \\ \\ /\\ / /  / _ \\ | '__|  / _ \\  / _` |   | '_ \\  | | | |   | |_     _____  | |\\/| |  / _ \\  / _` | | |  / _` |\n\t|  __/  | (_) |  \\ V  V /  |  __/ | |    |  __/ | (_| |   | |_) | | |_| |   |  _|   |_____| | |  | | |  __/ | (_| | | | | (_| |\n\t|_|      \\___/    \\_/\\_/    \\___| |_|     \\___|  \\__,_|   |_.__/   \\__, |   |_|             |_|  |_|  \\___|  \\__,_| |_|  \\__,_|\n\t\t\t\t\t\t\t\t\t   |___/\n\n";
        /*Txt a;
        a.p("Powered by F-Media");*/
        for (int i = 0; i < SCREEN_HEIGHT; i++)
        {
            for (int j = 0; j < SCREEN_WIDTH; j++)
            {
                this->m[i][j] = ' ';
            }
        }
    }

    char m[SCREEN_HEIGHT][SCREEN_WIDTH];

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
                if (this->m[i][j] != NULL)
                    std::cout << this->m[i][j];
                else
                    std::cout << " ";
            }
            std::cout << "|\n";
        }

        std::cout << "O";
        for (int i = 0; i < SCREEN_WIDTH; i++)
            std::cout << "-";
        std::cout << "#\n";
    }

    void clear()
    {
        for (int i = 0; i < SCREEN_HEIGHT; i++)
        {
            for (int j = 0; j < SCREEN_WIDTH; j++)
            {
                this->m[i][j] = false;
            }
        }
    }

    void add(vec2 a, char v = DEFAULT_COLOR)
    {
        this->m[SCREEN_HEIGHT - int(std::round(a.y)) - 1][int(std::round(a.x))] = v;
    }

    void add(std::vector<vec2> a, char v = DEFAULT_COLOR)
    {
        for (int i = 0; i < a.size(); i++)
        {
            this->m[SCREEN_HEIGHT - int(std::round(a[i].y)) - 1][int(std::round(a[i].x))] = v;
        }
    }

    void add(Fig::Rect a, char v = DEFAULT_COLOR)
    {
        if (!a.is_full)
        {
            this->add(line(a.pos, vec2(a.pos.x + a.w, a.pos.y)).gen(), v);
            this->add(line(a.pos, vec2(a.pos.x, a.pos.y + a.h)).gen(), v);
            this->add(line(vec2(a.pos.x + a.w, a.pos.y), vec2(a.pos.x + a.w, a.pos.y + a.h)).gen(), v);
            this->add(line(vec2(a.pos.x, a.pos.y + a.h), vec2(a.pos.x + a.w, a.pos.y + a.h)).gen(), v);
        }
        else
        {
            for (int i = 0; i < a.h; i++)
            {
                for (int j = 0; j < a.w; j++)
                {
                    this->add(vec2(j + a.pos.x, i + a.pos.y), v);
                }
            }
        }
    }

    void add(Fig::Tri t, char v = DEFAULT_COLOR)
    {
        this->add(line(t.a, t.b).gen(), v);
        this->add(line(t.b, t.c).gen(), v);
        this->add(line(t.c, t.a).gen(), v);
    }

    void add(Fig::Cir c, char v = DEFAULT_COLOR)
    {
        float x = c.r - 1.0F;
        float y = 0.0F;
        float d_x = 1.0F;
        float d_y = 1.0F;
        float e = d_x - (c.r * 2.0F);

        while (x >= y)
        {
            this->add(vec2(c.pos.x + x, c.pos.y + y), v);
            this->add(vec2(c.pos.x + y, c.pos.y + x), v);
            this->add(vec2(c.pos.x - y, c.pos.y + x), v);
            this->add(vec2(c.pos.x - x, c.pos.y + y), v);
            this->add(vec2(c.pos.x - x, c.pos.y - y), v);
            this->add(vec2(c.pos.x - y, c.pos.y - x), v);
            this->add(vec2(c.pos.x + y, c.pos.y - x), v);
            this->add(vec2(c.pos.x + x, c.pos.y - y), v);

            if (e > 0)
            {
                d_x += 2.0F;
                e += d_x - (c.r * 2.0F);
                x--;
            }
            else if (e <= 0)
            {
                e += d_y;
                d_y += 2.0F;
                y++;
            }
        }
    }
};
#endif