/*
** EPITECH PROJECT, 2022
** AObject.cpp
** File description:
** AObject
*/

#include "AObject.hpp"

namespace IS {
    AObject::AObject(const Vector3 &position, const Vector3 &dimensions, const Vector3 &scale, const Color &color, const Vector3 &speed) :
        _is{false},
        _position(position),
        _dimensions(dimensions),
        _scale(scale),
        _color(color),
        _speed(speed)
    {
    }

    bool AObject::getIsCategory(const objectCategory_e &category)
    {
        return _is[category];
    }

    void AObject::setIsCategory(const bool &value, const objectCategory_e &category)
    {
        _is[category] = value;
    }

    Vector3 AObject::getPosition()
    {
        return _position;
    }

    void AObject::setPosition(const Vector3 &position)
    {
        _position = position;
    }

    Vector3 AObject::getDimensions()
    {
        return _dimensions;
    }

    void AObject::setDimensions(const Vector3 &dimensions)
    {
        _dimensions = dimensions;
    }

    Vector3 AObject::getScale()
    {
        return _scale;
    }

    void AObject::setScale(const Vector3 &scale)
    {
        _scale = scale;
    }

    Color AObject::getColor()
    {
        return _color;
    }

    void AObject::setColor(const Color &color)
    {
        _color = color;
    }

    Vector3 AObject::getSpeed()
    {
        return _speed;
    }

    void AObject::setSpeed(const Vector3 &speed)
    {
        _speed = speed;
    }
}
