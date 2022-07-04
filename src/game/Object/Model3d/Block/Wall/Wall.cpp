/*
** EPITECH PROJECT, 2022
** Wall.cpp
** File description:
** Wall
*/

#include "Wall.hpp"

namespace IS {
    Wall::Wall(const Vector3 &position, const Vector3 &dimensions, const std::string &path) :
        Block(position, dimensions, path)
    {
        setIsCategory(true, WALL);
    }
}
