/*
** EPITECH PROJECT, 2022
** Vector2.hpp
** File description:
** Vector2
*/

#ifndef VECTOR2_HPP_
#define VECTOR2_HPP_

#include "raylib.h"

namespace IS {
    class Vector2 : public ::Vector2 {
        public:
            Vector2(float x = 0, float y = 0) :
                ::Vector2{x, y}
            {
            }

            Vector2(const ::Vector2 &vector2)
            {
                set(vector2);
            }

            Vector2 operator+(const float &val) const
            {
                return (Vector2(x + val, y + val));
            }

            Vector2 operator-(const float &val) const
            {
                return (Vector2(x - val, y - val));
            }

            Vector2 operator*(const float &val) const
            {
                return (Vector2(x * val, y * val));
            }

            Vector2 operator/(const float &val) const
            {
                return (Vector2(x / val, y / val));
            }

            Vector2 &operator+=(const float &val)
            {
                x += val;
                y += val;
                return *this;
            }

            Vector2 &operator-=(const float &val)
            {
                x -= val;
                y -= val;
                return *this;
            }

            Vector2 &operator*=(const float &val)
            {
                x *= val;
                y *= val;
                return *this;
            }

            Vector2 &operator/=(const float &val)
            {
                x /= val;
                y /= val;
                return *this;
            }

            Vector2 &operator=(const ::Vector2 &other)
            {
                set(other);
                return *this;
            }

            Vector2 operator+(const ::Vector2 &other) const
            {
                return (Vector2(x + other.x, y + other.y));
            }

            Vector2 operator-(const ::Vector2 &other) const
            {
                return (Vector2(x - other.x, y - other.y));
            }

            Vector2 operator*(const ::Vector2 &other) const
            {
                return (Vector2(x * other.x, y * other.y));
            }

            Vector2 operator/(const ::Vector2 &other) const
            {
                return (Vector2(x / other.x, y / other.y));
            }

            Vector2 &operator+=(const ::Vector2 &other)
            {
                x += other.x;
                y += other.y;
                return *this;
            }

            Vector2 &operator-=(const ::Vector2 &other)
            {
                x -= other.x;
                y -= other.y;
                return *this;
            }

            Vector2 &operator*=(const ::Vector2 &other)
            {
                x *= other.x;
                y *= other.y;
                return *this;
            }

            Vector2 &operator/=(const ::Vector2 &other)
            {
                x /= other.x;
                y /= other.y;
                return *this;
            }

            bool operator==(const ::Vector2 &other) const
            {
                return (x == other.x && y == other.y);
            }

            bool operator!=(const ::Vector2 &other) const
            {
                return (x != other.x || y != other.y);
            }

        private:
            void set(const ::Vector2 &vector2)
            {
                x = vector2.x;
                y = vector2.y;
            }
    };
}

#endif /* !VECTOR2_HPP_ */
