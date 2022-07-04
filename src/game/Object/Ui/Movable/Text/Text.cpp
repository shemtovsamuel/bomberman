/*
** EPITECH PROJECT, 2022
** Text.cpp
** File description:
** Text
*/

#include "Text.hpp"

namespace IS {
    Text::Text(const Vector3 &position, const Vector3 &scale, const Color &color, const Vector3 &speed, const std::string &font_path, const bool &reset, const Vector3 &end_pos, const std::string &content, const float &font_size, const float &spacing) :
        Movable(position, Vector3(), Vector3(), color, speed, font_path, reset, end_pos),
        _content(content),
        _font_size(font_size),
        _spacing(spacing)
    {
        setIsCategory(true, TEXT);
    }

    std::string Text::getContent()
    {
        return _content;
    }

    void Text::setContent(const std::string &content)
    {
        _content = content;
    }

    float Text::getFontSize()
    {
        return _font_size;
    }

    void Text::setFontSize(const float &font_size)
    {
        _font_size = font_size;
    }

    float Text::getSpacing()
    {
        return _spacing;
    }

    void Text::setSpacing(const float &spacing)
    {
        _spacing = spacing;
    }
}
