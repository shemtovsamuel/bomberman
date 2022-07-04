/*
** EPITECH PROJECT, 2022
** Button.cpp
** File description:
** Button
*/

#include "Button.hpp"
// #define NUM_FRAMES  3

namespace IS {
    Button::Button(const Vector3 &position, const Vector3 &dimensions, const Vector3 &scale, const std::string &texture_path, const std::string &sound_path, const std::function<void()> &callback) :
        Ui(position, dimensions, scale, Color(), 0, texture_path),
        _frame_height(dimensions.y),
        _texture_rec(Rectangle(0, 0, dimensions.x, dimensions.y)),
        _sound_path(sound_path),
        _callback(callback)
    {
        setIsCategory(true, BUTTON);
    }

    Rectangle Button::getTextureRec()
    {
        return _texture_rec;
    }

    void Button::setTextureRec(const state_e &state)
    {
        _texture_rec.y = state * _frame_height;
    }

    void Button::setCallback(std::function<void()> callback)
    {
        _callback = callback;
    }

    void Button::triggerButton(Audio &audio, Event &event, std::shared_ptr<Button> button)
    {
        if (event.isCursorInRange(Rectangle(getPosition().x, getPosition().y, getDimensions().x, getDimensions().y))) {
            setTextureRec(HOVER);
            if (event.isMouseButtonLeftPressed())
                audio.playSound(_sound_path);
            if (event.isMouseButtonLeftDown())
                setTextureRec(CLICKED);
            if (event.isMouseButtonLeftReleased())
                _callback();
        } else
            setTextureRec(NORMAL);
    }
}
