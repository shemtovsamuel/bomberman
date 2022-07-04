/*
** EPITECH PROJECT, 2022
** Rectangle.hpp
** File description:
** Rectangle
*/

#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_

#include "raylib.h"

namespace IS {
    class Rectangle : public ::Rectangle {
        public:
            Rectangle(float x = 0, float y = 0, float width = 0, float height = 0) :
                ::Rectangle{x, y, width, height}
            {
            }

            Rectangle(::Vector2 position, ::Vector2 size) :
                ::Rectangle{position.x, position.y, size.x, size.y}
            {
            }

            Rectangle(const ::Rectangle &rectangle)
            {
                set(rectangle);
            }

            Rectangle &operator=(const ::Rectangle &other)
            {
                set(other);
                return *this;
            }

        private:
            void set(const ::Rectangle &rectangle)
            {
                x = rectangle.x;
                y = rectangle.y;
                width = rectangle.width;
                height = rectangle.height;
            }
    };
}

#endif /* !RECTANGLE_HPP_ */
