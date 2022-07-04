/*
** EPITECH PROJECT, 2022
** Block.cpp
** File description:
** Block
*/

#include "Block.hpp"

namespace IS {
    Block::Block(const Vector3 &position, const Vector3 &dimensions, const std::string &path) :
        Model3d(position, dimensions, Vector3(1, 1), Vector3(), Vector3(), 0, path, "")
    {
        setIsCategory(true, BLOCK);
    }
}
