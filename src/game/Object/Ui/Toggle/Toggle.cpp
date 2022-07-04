/*
** EPITECH PROJECT, 2022
** Toggle.cpp
** File description:
** Toggle
*/

#include "Toggle.hpp"

namespace IS {
    Toggle::Toggle(const Vector3 &position, const Vector3 &dimensions, const Vector3 &scale, const std::pair<std::string, std::string> &state_texture_paths, const bool &active, const float &frame_height, const Rectangle &texture_rec, const std::string &sound_path, const std::function<void()> &callback) :
        Ui(position, dimensions, scale, Color::White(), 0, state_texture_paths.first),
        _state_texture_paths(state_texture_paths),
        _active(active),
        _frame_height(frame_height),
        _texture_rec(texture_rec),
        _sound_path(sound_path),
        _callback(callback)
    {
        setIsCategory(true, TOGGLE);
    }

    bool Toggle::getActive()
    {
        return _active;
    }

    void Toggle::setActive(bool active)
    {
        _active = active;
    }

    void Toggle::changeActive()
    {
        _active = !_active;
    }

    Rectangle Toggle::getTextureRec()
    {
        return _texture_rec;
    }

    void Toggle::setTextureRec(const state_e &state)
    {
        _texture_rec.y = state * _frame_height;
    }

    void Toggle::setCallback(std::function<void()> callback)
    {
        _callback = callback;
    }

    void Toggle::triggerToggle(Audio &audio, Event &event)
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
        _callback();
    }
}
