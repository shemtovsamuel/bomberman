/*
** EPITECH PROJECT, 2022
** Error.cpp
** File description:
** Error
*/

#include "Error.hpp"

namespace IS {
    Error::Error(std::string what, std::string where) noexcept :
        _what(what),
        _where(where.append(": "))
    {
    }

    const char *Error::what() const noexcept
    {
        return _what.c_str();
    }

    const char *Error::where() const noexcept
    {
        return _where.c_str();
    }
}
