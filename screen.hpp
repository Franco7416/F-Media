#ifndef F_MEDIA_SCREEN_HPP
#define F_MEDIA_SCREEN_HPP
#include "fmediaconfig.h"
#include <vector>
#include "vec2.hpp"
#include <iostream>
#include <vector>
class Screen
{
public:
    Screen() {}

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
};
#endif