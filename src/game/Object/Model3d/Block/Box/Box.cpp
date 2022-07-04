/*
** EPITECH PROJECT, 2022
** Box.cpp
** File description:
** Box
*/

#include "Box.hpp"

namespace IS {
    Box::Box(const Vector3 &position, const Vector3 &dimensions, const std::string &path) :
        Block(position, dimensions, path)
    {
        setIsCategory(true, BOX);
    }
}
