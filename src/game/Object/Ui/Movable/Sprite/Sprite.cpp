/*
** EPITECH PROJECT, 2022
** Sprite.cpp
** File description:
** Sprite
*/

#include "Sprite.hpp"

namespace IS {
    Sprite::Sprite(const Vector3 &position, const Vector3 &dimensions, const Vector3 &scale, const Vector3 &speed, const std::string &texture_path, const bool &reset, const Vector3 &end_pos) :
        Movable(position, dimensions, scale, Color::White(), speed, texture_path, reset, end_pos)
    {
        setIsCategory(true, SPRITE);
    }
}