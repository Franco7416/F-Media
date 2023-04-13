#ifndef F_MEDIA_SCREEN_HPP
#define F_MEDIA_SCREEN_HPP
#include <iostream>
#include <cmath>
#include <vector>
#include "config.hpp"
#include "col.hpp"
#include "vec2.hpp"
#include "rect.hpp"
#include "line.hpp"
#include "tri.hpp"
#include "cir.hpp"
#include "quad.hpp"
#include "sprite.hpp"

namespace FM
{
    class Screen
    {
    private:
        const char *colorize(int font, int back = -1, int style = -1)
        {
            static char code[20];
            back = font;
            if (font >= 0)
                font += 30;
            else
                font = 0;
            if (back >= 0)
                back += 40;
            else
                back = 0;
            if (back > 0 && style > 0)
                sprintf(code, "\033[%d;%d;%dm", font, back, style);
            else if (back > 0)
                sprintf(code, "\033[%d;%dm", font, back);
            else
                sprintf(code, "\033[%dm", font);
            return code;
        }

    public:
        FM::col m[F_MEDIA_CONFIG_SCREEN_HEIGHT][F_MEDIA_CONFIG_SCREEN_WIDTH];
        Screen()
        {
            std::cout << "Powered By F-Media 2.0\n";
            for (int i = 0; i < F_MEDIA_CONFIG_SCREEN_HEIGHT; i++)
            {
                for (int j = 0; j < F_MEDIA_CONFIG_SCREEN_WIDTH; j++)
                {
                    this->m[i][j] = F_MEDIA_CONFIG_SCREEN_BACKGROUND_COLOR;
                }
            }
        }
        void draw()
        {
            std::cout << "#";
            for (int i = 0; i < F_MEDIA_CONFIG_SCREEN_WIDTH; i++)
                std::cout << "-";
            std::cout << "#\n";

            for (int i = 0; i < F_MEDIA_CONFIG_SCREEN_HEIGHT; i++)
            {
                std::cout << "|";
                for (int j = 0; j < F_MEDIA_CONFIG_SCREEN_WIDTH; j++)
                {
                    // m[i][j]
                    std::cout << this->colorize(m[i][j].color, m[i][j].bg) << m[i][j].car << this->colorize(FM::Colors::NC, FM::Colors::NC);
                }
                std::cout << "|\n";
            }

            std::cout << "O";
            for (int i = 0; i < F_MEDIA_CONFIG_SCREEN_WIDTH; i++)
                std::cout << "-";
            std::cout << "#\n";
        }

        void clear(col c = F_MEDIA_CONFIG_SCREEN_BACKGROUND_COLOR)
        {
            for (int i = 0; i < F_MEDIA_CONFIG_SCREEN_HEIGHT; i++)
            {
                for (int j = 0; j < F_MEDIA_CONFIG_SCREEN_WIDTH; j++)
                {
                    this->m[i][j] = c;
                }
            }
        }

        void add(FM::vec2 v, FM::col c = F_MEDIA_CONFIG_DEFAULT_COLOR)
        {
            this->m[F_MEDIA_CONFIG_SCREEN_HEIGHT - int(std::round(v.y)) - 1][int(std::round(v.x))] = c;
        }

        void add(std::vector<FM::vec2> v, FM::col c = F_MEDIA_CONFIG_DEFAULT_COLOR)
        {
            for (int i = 0; i < v.size(); i++)
            {
                this->add(v[i], c);
            }
        }

        void add(FM::line l, FM::col c = F_MEDIA_CONFIG_DEFAULT_COLOR)
        {
            this->add(l.gen(), c);
        }

        void add(FM::Rect r, FM::col c = F_MEDIA_CONFIG_DEFAULT_COLOR)
        {
            if (r.is_full)
            {
                for (int i = 0; i < r.h; i++)
                {
                    for (int j = 0; j < r.w; j++)
                    {
                        this->add(FM::vec2(j + r.pos.x, i + r.pos.y), c);
                    }
                }
            }
            else
            {
                this->add(FM::line(r.pos, FM::vec2(r.pos.x + r.w, r.pos.y)).gen(), c);
                this->add(FM::line(r.pos, FM::vec2(r.pos.x, r.pos.y + r.h)).gen(), c);
                this->add(FM::line(FM::vec2(r.pos.x + r.w, r.pos.y), vec2(r.pos.x + r.w, r.pos.y + r.h)).gen(), c);
                this->add(FM::line(FM::vec2(r.pos.x, r.pos.y + r.h), vec2(r.pos.x + r.w, r.pos.y + r.h)).gen(), c);
            }
        }

        void add(FM::Tri t, FM::col c = F_MEDIA_CONFIG_DEFAULT_COLOR)
        {
            if (t.is_full)
            {
                t.sort_y_vec();

                std::vector<vec2> Vab = line(t.a, t.b).gen();
                std::vector<vec2> Vbc = line(t.b, t.c).gen();
                std::vector<vec2> Vca = line(t.c, t.a).gen();

                for (int i = 0; i < Vab.size(); i++)
                    this->add(line(t.c, Vab[i]).gen(), c);

                for (int i = 0; i < Vbc.size(); i++)
                    this->add(line(t.a, Vbc[i]).gen(), c);

                for (int i = 0; i < Vca.size(); i++)
                {
                    this->add(line(t.b, Vca[i]).gen(), c);
                }
            }
            else
            {
                this->add(FM::line(t.a, t.b).gen(), c);
                this->add(FM::line(t.b, t.c).gen(), c);
                this->add(FM::line(t.a, t.c).gen(), c);
            }
        }

        void add(FM::Cir c, FM::col color = F_MEDIA_CONFIG_DEFAULT_COLOR)
        {
            if (c.is_full)
            {
                for (int i = 0; i < c.r; i++)
                {
                    this->add(FM::Cir(c.pos, i, false), color);
                }
            }
            else
            {
                float x = c.r - 1.0F;
                float y = 0.0F;
                float d_x = 1.0F;
                float d_y = 1.0F;
                float e = d_x - (c.r * 2.0F);

                while (x >= y)
                {
                    this->add(FM::vec2(c.pos.x + x, c.pos.y + y), color);
                    this->add(FM::vec2(c.pos.x + y, c.pos.y + x), color);
                    this->add(FM::vec2(c.pos.x - y, c.pos.y + x), color);
                    this->add(FM::vec2(c.pos.x - x, c.pos.y + y), color);
                    this->add(FM::vec2(c.pos.x - x, c.pos.y - y), color);
                    this->add(FM::vec2(c.pos.x - y, c.pos.y - x), color);
                    this->add(FM::vec2(c.pos.x + y, c.pos.y - x), color);
                    this->add(FM::vec2(c.pos.x + x, c.pos.y - y), color);

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
        }

        void add(FM::Quad q, FM::col c = F_MEDIA_CONFIG_DEFAULT_COLOR)
        {
            if (q.is_full)
            {
                FM::Tri abc(q.a, q.b, q.c, true);
                FM::Tri acd(q.a, q.c, q.d, true);
                this->add(abc, c);
                this->add(acd, c);
            }
            else
            {
                this->add(FM::line(q.a, q.b).gen(), c);
                this->add(FM::line(q.b, q.c).gen(), c);
                this->add(FM::line(q.c, q.d).gen(), c);
                this->add(FM::line(q.a, q.d).gen(), c);
            }
        }

        void add(FM::Px p)
        {
            if (!p.is_t)
                this->add(p.pos, p.c);
        }

        void add(FM::Sprite s, vec2 pos = vec2(0, 0))
        {
            for (int i = 0; i < s.s.size(); i++)
            {
                this->add(Px(vec2(s.s[i].pos.x + pos.x, s.s[i].pos.y + pos.y), s.s[i].c));
            }
        }
    };
};
#endif