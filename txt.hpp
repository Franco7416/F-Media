#ifndef F_MEDIA_TXT_HPP
#define F_MEDIA_TXT_HPP
#include "vec2.hpp"
#include <string>
#include <array>
#include <unordered_map>
using std::string;
class Txt
{
public:
    std::unordered_map<string, std::array<std::string, 6>> lm;
    Txt()
    {
        lm["a"] = std::array<string, 6>{
            "        ",
            "   __ _ ",
            "  / _` |",
            " | (_| |",
            "  \\__,_|",
            "        "};
        lm["b"] = std::array<string, 6>{
            "  _     ",
            " | |__  ",
            " | '_ \\ ",
            " | |_) |",
            " |_.__/ ",
            "       "};
        lm["c"] = std::array<string, 6>{
            "        ",
            "   ___  ",
            "  / __| ",
            " | (__  ",
            "  \\___| ",
            "        "};
        lm["d"] = std::array<string, 6>{
            "      _ ",
            "   __| |",
            "  / _` |",
            " | (_| |",
            "  \\__,_|",
            "        "};
        lm["e"] = std::array<string, 6>{
            "       ",
            "   ___ ",
            "  / _ \\",
            " |  __/",
            "  \\___|",
            "       "};
        lm["f"] = std::array<string, 6>{
            "   __ ",
            "  / _|",
            " | |_ ",
            " |  _|",
            " |_|  ",
            "      "};
        lm["g"] = std::array<string, 6>{
            "        ",
            "   __ _ ",
            "  / _` |",
            " | (_| |",
            "  \\__, |",
            "  |___/ "};
        lm["h"] = std::array<string, 6>{
            "  _     ",
            " | |__  ",
            " | '_ \\ ",
            " | | | |",
            " |_| |_|",
            "        "};
        lm["i"] = std::array<string, 6>{
            "  _ ",
            " (_)",
            " | |",
            " | |",
            " |_|",
            "    "};
        lm["j"] = std::array<string, 6>{
            "    _ ",
            "   (_)",
            "   | |",
            "   | |",
            "  _/ |",
            " |__/ "};
        lm["k"] = std::array<string, 6>{
            "  _    ",
            " | | __",
            " | |/ /",
            " |   < ",
            " |_|\\_\\",
            "       "};
        lm["l"] = std::array<string, 6>{
            "  _ ",
            " | |",
            " | |",
            " | |",
            " |_|",
            "    "};
        lm["m"] = std::array<string, 6>{
            "            ",
            "  _ __ ___  ",
            " | '_ ` _ \\ ",
            " | | | | | |",
            " |_| |_| |_|",
            "            "};
        lm["n"] = std::array<string, 6>{
            "        ",
            "  _ __  ",
            " | '_ \\ ",
            " | | | |",
            " |_| |_|",
            "        "};
        lm["o"] = std::array<string, 6>{
            "        ",
            "   ___  ",
            "  / _ \\ ",
            " | (_) |",
            "  \\___/ ",
            "        "};
        lm["p"] = std::array<string, 6>{
            "        ",
            "  _ __  ",
            " | '_ \\ ",
            " | |_) |",
            " | .__/ ",
            " |_|    "};
        lm["q"] = std::array<string, 6>{
            "        ",
            "   __ _ ",
            "  / _` |",
            " | (_| |",
            "  \\__, |",
            "     |_|"};
        lm["r"] = std::array<string, 6>{
            "       ",
            "  _ __ ",
            " | '__|",
            " | |   ",
            " |_|   ",
            "       "};
        lm["s"] = std::array<string, 6>{
            "      ",
            "  ___ ",
            " / __|",
            " \\__ \\",
            " |___/",
            "      "};
        lm["t"] = std::array<string, 6>{
            "  _   ",
            " | |_ ",
            " |  _|",
            " | |_ ",
            "  \\__|",
            "      "};
        lm["u"] = std::array<string, 6>{
            "        ",
            "  _   _ ",
            " | | | |",
            " | |_| |",
            "  \\__,_|",
            "        "};
        lm["v"] = std::array<string, 6>{
            "        ",
            " __   __",
            " \\ \\ / /",
            "  \\ V / ",
            "   \\_/  ",
            "        "};
        lm["w"] = std::array<string, 6>{
            "           ",
            " __      __",
            " \\ \\ /\\ / /",
            "  \\ V  V / ",
            "   \\_/\\_/  ",
            "           "};
        lm["x"] = std::array<string, 6>{
            "       ",
            " __  __",
            " \\ \\/ /",
            "  >  < ",
            " /_/\\_\\",
            "       "};
        lm["y"] = std::array<string, 6>{
            "        ",
            "  _   _ ",
            " | | | |",
            " | |_| |",
            "  \\__, |",
            "  |___/ "};
        lm["z"] = std::array<string, 6>{
            "      ",
            "  ____",
            " |_  /",
            "  / / ",
            " /___|",
            "      "};
        lm[" "] = std::array<string, 6>{
            "      ",
            "      ",
            "      ",
            "      ",
            "      ",
            "      "};
    };
    void p(string l)
    {
        std::array<string, 6> out = {"", "", "", "", "", ""};
        for (int i = 0; i < l.length(); i++)
        {
            string curr_car(1, l[i]);
            out[0] += this->lm[curr_car][0];
            out[1] += this->lm[curr_car][1];
            out[2] += this->lm[curr_car][2];
            out[3] += this->lm[curr_car][3];
            out[4] += this->lm[curr_car][4];
            out[5] += this->lm[curr_car][5];
        }

        for (int i = 0; i < 6; i++)
        {
            std::cout << out[i] << "\n";
        }
    }
};
#endif