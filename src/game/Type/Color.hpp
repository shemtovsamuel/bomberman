/*
** EPITECH PROJECT, 2022
** Color.hpp
** File description:
** Color
*/

#ifndef COLOR_HPP_
#define COLOR_HPP_

#include "raylib.h"

namespace IS {
    class Color : public ::Color {
        public:
            Color(unsigned char _r = 255, unsigned char _g = 255, unsigned char _b = 255, unsigned char _a = 255) :
                ::Color{_r, _g, _b, _a}
            {
            }

            Color(const ::Color &color)
            {
                set(color);
            }

            Color &operator=(const ::Color &other)
            {
                set(other);
                return *this;
            };

            static Color Lightgray() { return LIGHTGRAY; }
            static Color Gray() { return GRAY; }
            static Color DarkGray() { return DARKGRAY; }
            static Color Yellow() { return YELLOW; }
            static Color Gold() { return GOLD; }
            static Color Orange() { return ORANGE; }
            static Color Pink() { return PINK; }
            static Color Red() { return RED; }
            static Color Maroon() { return MAROON; }
            static Color Green() { return GREEN; }
            static Color Lime() { return LIME; }
            static Color DarkGreen() { return DARKGREEN; }
            static Color SkyBlue() { return SKYBLUE; }
            static Color Blue() { return BLUE; }
            static Color DarkBlue() { return DARKBLUE; }
            static Color Purple() { return PURPLE; }
            static Color Violet() { return VIOLET; }
            static Color DarkPurple() { return DARKPURPLE; }
            static Color Beige() { return BEIGE; }
            static Color Brown() { return BROWN; }
            static Color DarkBrown() { return DARKBROWN; }
            static Color White() { return WHITE; }
            static Color Black() { return BLACK; }
            static Color Blank() { return BLANK; }
            static Color Magenta() { return MAGENTA; }
            static Color RayWhite() { return RAYWHITE; }

        private:
            void set(const ::Color &color)
            {
                r = color.r;
                g = color.g;
                b = color.b;
                a = color.a;
            }
    };
}

#endif /* !COLOR_HPP_ */
