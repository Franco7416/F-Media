#ifndef F_MEDIA_COL_HPP
#define F_MEDIA_COL_HPP
namespace FM
{
    namespace Colors
    {
        const int Black = 0;
        const int Red = 1;
        const int Green = 2;
        const int Yellow = 3;
        const int Blue = 4;
        const int Purple = 5;
        const int Cyan = 6;
        const int White = 7;

        const int Bright_Black = 60;
        const int Bright_Red = 61;
        const int Bright_Green = 62;
        const int Bright_Yellow = 63;
        const int Bright_Blue = 64;
        const int Bright_Purple = 65;
        const int Bright_Cyan = 66;
        const int Bright_White = 67;

        const int NC = -1;
    };

    class col
    {
    public:
        char color;
        char car;
        char bg;

        col()
        {
            this->car = ' ';
            this->color = FM::Colors::NC;
            this->bg = FM::Colors::NC;
        }
        col(int color, char car, int bg)
        {
            this->color = color;
            this->car = car;
            this->bg = bg;
        }

        col(int color, char car)
        {
            this->color = color;
            this->car = car;
            this->bg = color;
        }

        col(int color)
        {
            this->color = color;
            this->car = '@';
            this->bg = color;
        }
    };
};
#endif