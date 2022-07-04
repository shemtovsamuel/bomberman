/*
** EPITECH PROJECT, 2022
** Ground.cpp
** File description:
** Ground
*/

#include "Ground.hpp"

namespace IS {
    Ground::Ground(const Vector3 &position, const Vector3 &dimensions, const std::string &path) :
        Block(position, dimensions, path)
    {
        setIsCategory(true, GROUND);
    }
}
