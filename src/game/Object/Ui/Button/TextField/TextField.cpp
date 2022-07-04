/*
** EPITECH PROJECT, 2022
** TextField.cpp
** File description:
** TextField
*/

#include "TextField.hpp"

namespace IS {
    TextField::TextField(const Vector3 &position, const Vector3 &dimensions, const Vector3 &scale, const std::string &texture_path, const std::string &sound_path, const Vector3 offset, const Color &color, const std::string &font_path, const float &font_size, const float &spacing, const unsigned int &limit) :
        Button(position, dimensions, scale, texture_path, sound_path, [](){}),
        _text(std::make_unique<Text>(position + offset, Vector3(), color, Vector3(), font_path, false, Vector3(), "", font_size, spacing)),
        _limit(limit)
    {
        setIsCategory(true, TEXT_FIELD);
    }

    const Text &TextField::getText()
    {
        return *_text;
    }

    void TextField::setText(std::unique_ptr<Text> text)
    {
        _text = std::move(text);
    }

    unsigned int TextField::getLimit()
    {
        return _limit;
    }

    void TextField::setLimit(unsigned int limit)
    {
        _limit = limit;
    }

    void TextField::appendMarker()
    {
        std::string content = _text->getContent();

        if (content.size() < _limit) {
            content.push_back('_');
            _text->setContent(content);
        }
    }

    void TextField::replaceLast(char c)
    {
        std::string content = _text->getContent();

        if (c == -1 && content.size() > 1) {
            if (content.size() < _limit)
                content.erase(content.begin() + (content.size() - 2));
            else
                content.back() = '_';
            _text->setContent(content);
        }
        if (c != 0 && content.size() < (_limit + 1)) {
            content.back() = c;
            if (content.size() < _limit)
                content.push_back('_');
            _text->setContent(content);
        }
    }

    void TextField::popMarker()
    {
        std::string content = _text->getContent();

        if (content.size() < _limit) {
            content.pop_back();
            _text->setContent(content);
        }
    }
}
