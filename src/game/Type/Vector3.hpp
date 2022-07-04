/*
** EPITECH PROJECT, 2022
** Vector3.hpp
** File description:
** Vector3
*/

#ifndef VECTOR3_HPP_
#define VECTOR3_HPP_

#include "raylib.h"

namespace IS {
    class Vector3 : public ::Vector3 {
        public:
            Vector3(float _x = 0, float _y = 0, float _z = 0) :
                ::Vector3{_x, _y, _z}
            {
            }

            Vector3(const ::Vector3 &vector3)
            {
                set(vector3);
            }

            Vector3 operator+(const float &val) const
            {
                return (Vector3(x + val, y + val, z + val));
            }

            Vector3 operator-(const float &val) const
            {
                return (Vector3(x - val, y - val, z - val));
            }

            Vector3 operator*(const float &val) const
            {
                return (Vector3(x * val, y * val, z * val));
            }

            Vector3 operator/(const float &val) const
            {
                return (Vector3(x / val, y / val, z / val));
            }

            Vector3 &operator+=(const float &val)
            {
                x += val;
                y += val;
                z += val;
                return *this;
            }

            Vector3 &operator-=(const float &val)
            {
                x -= val;
                y -= val;
                z -= val;
                return *this;
            }

            Vector3 &operator*=(const float &val)
            {
                x *= val;
                y *= val;
                z *= val;
                return *this;
            }

            Vector3 &operator/=(const float &val)
            {
                x /= val;
                y /= val;
                z /= val;
                return *this;
            }

            Vector3 &operator=(const ::Vector3 &other)
            {
                set(other);
                return *this;
            }

            Vector3 operator+(const ::Vector3 &other) const
            {
                return (Vector3(x + other.x, y + other.y, z + other.z));
            }

            Vector3 operator-(const ::Vector3 &other) const
            {
                return (Vector3(x - other.x, y - other.y, z + other.z));
            }

            Vector3 operator*(const ::Vector3 &other) const
            {
                return (Vector3(x * other.x, y * other.y, z * other.z));
            }

            Vector3 operator/(const ::Vector3 &other) const
            {
                return (Vector3(x / other.x, y / other.y, z / other.z));
            }

            Vector3 &operator+=(const ::Vector3 &other)
            {
                x += other.x;
                y += other.y;
                z += other.z;
                return *this;
            }

            Vector3 &operator-=(const ::Vector3 &other)
            {
                x -= other.x;
                y -= other.y;
                z -= other.z;
                return *this;
            }

            Vector3 &operator*=(const ::Vector3 &other)
            {
                x *= other.x;
                y *= other.y;
                z *= other.z;
                return *this;
            }

            Vector3 &operator/=(const ::Vector3 &other)
            {
                x /= other.x;
                y /= other.y;
                z /= other.z;
                return *this;
            }

            bool operator==(const ::Vector3 &other) const
            {
                return (x == other.x && y == other.y && z == other.z);
            }

            bool operator!=(const ::Vector3 &other) const
            {
                return (x != other.x || y != other.y || z != other.z);
            }

        private:
            void set(const ::Vector3 &vector3)
            {
                x = vector3.x;
                y = vector3.y;
                z = vector3.z;
            }
    };
}

#endif /* !VECTOR3_HPP_ */
