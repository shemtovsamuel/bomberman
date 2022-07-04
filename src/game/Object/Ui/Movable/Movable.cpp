/*
** EPITECH PROJECT, 2022
** Movable.cpp
** File description:
** Movable
*/

#include "Movable.hpp"

namespace IS {
    Movable::Movable(const Vector3 &position, const Vector3 &dimensions, const Vector3 &scale, const Color &color, const Vector3 &speed, const std::string &path, const bool &reset, const Vector3 &end_pos) :
        Ui(position, dimensions, scale, color, speed, path),
        _reset(reset),
        _init_pos(position),
        _end_pos(end_pos)
    {
        setIsCategory(true, MOVABLE);
    }

    bool Movable::getReset()
    {
        return _reset;
    }

    void Movable::setReset(const bool &reset)
    {
        _reset = reset;
    }

    Vector3 Movable::getInitPos()
    {
        return _init_pos;
    }

    void Movable::setInitPos(const Vector3 &init_pos)
    {
        _init_pos = init_pos;
    }

    Vector3 Movable::getEndPos()
    {
        return _end_pos;
    }

    void Movable::setEndPos(const Vector3 &end_pos)
    {
        _end_pos = end_pos;
    }
}