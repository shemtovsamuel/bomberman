/*
** EPITECH PROJECT, 2022
** Bonus.cpp
** File description:
** Bonus
*/

#include "Bonus.hpp"

namespace IS {
    Bonus::Bonus(const Vector3 &position, const Vector3 &dimensions, const std::string &path, const bonus_e &bonus) :
        Block(position, dimensions, path),
        _bonus(bonus)
    {
        setIsCategory(true, BONUS);
    }
}
