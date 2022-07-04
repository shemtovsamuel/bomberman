/*
** EPITECH PROJECT, 2022
** Ui.cpp
** File description:
** Ui
*/

#include "Ui.hpp"

namespace IS {
    Ui::Ui(const Vector3 &position, const Vector3 &dimensions, const Vector3 &scale, const Color &color, const Vector3 &speed, const std::string &path) :
        AObject(position, dimensions, scale, color, speed),
        _texture_path(path)
    {
        setIsCategory(true, UI);
    }

    std::string Ui::getTexturePath()
    {
        return _texture_path;
    }

    void Ui::setTexturePath(const std::string &texture_path)
    {
        _texture_path = texture_path;
    }
}
