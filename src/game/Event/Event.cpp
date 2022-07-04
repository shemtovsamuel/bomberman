/*
** EPITECH PROJECT, 2022
** Event.cpp
** File description:
** Event
*/

#include "Event.hpp"

namespace IS {
    Event::Event() :
        _keys_repertory {
            KEY_A,
            KEY_B,
            KEY_C,
            KEY_D,
            KEY_E,
            KEY_F,
            KEY_G,
            KEY_H,
            KEY_I,
            KEY_J,
            KEY_K,
            KEY_L,
            KEY_M,
            KEY_N,
            KEY_O,
            KEY_P,
            KEY_Q,
            KEY_R,
            KEY_S,
            KEY_T,
            KEY_U,
            KEY_V,
            KEY_W,
            KEY_X,
            KEY_Y,
            KEY_Z,
            KEY_SPACE,
            KEY_ENTER,
            KEY_BACKSPACE,
            KEY_RIGHT,
            KEY_LEFT,
            KEY_DOWN,
            KEY_UP
        },
        _keys_monitored {},
        _keys_queue {}
    {
    }

    bool Event::isMouseButtonLeftPressed()
    {
        return (IsMouseButtonPressed(MOUSE_BUTTON_LEFT));
    }

    bool Event::isMouseButtonLeftDown()
    {
        return (IsMouseButtonDown(MOUSE_BUTTON_LEFT));
    }

    bool Event::isMouseButtonLeftReleased()
    {
        return (IsMouseButtonReleased(MOUSE_BUTTON_LEFT));
    }

    Vector2 Event::getMousePosition()
    {
        return (GetMousePosition());
    }

    bool Event::checkCollisionPointRec(Vector2 point, Rectangle rec)
    {
        return (CheckCollisionPointRec(point, rec));
    }

    bool Event::isCursorInRange(Rectangle rec)
    {
        return checkCollisionPointRec(getMousePosition(), rec);
    }

    void Event::setKeysMonitored(std::vector<int> keys_monitored)
    {
        _keys_monitored = keys_monitored;
    }

    int Event::getKeyPressed()
    {
        int key = GetKeyPressed();
        auto it_repertory = std::find(_keys_repertory.begin(), _keys_repertory.end(), key);

        if (it_repertory != _keys_repertory.end()) {
            int idx_key = std::distance(_keys_repertory.begin(), it_repertory);
            auto it_monitored = std::find(_keys_monitored.begin(), _keys_monitored.end(), idx_key);
            if (it_monitored != _keys_monitored.end())
                return idx_key;
        }
        return (0);
    }

    std::vector<int> Event::getKeysDown()
    {
        int key;
        std::vector<int> keys_down = {};

        while (key = getKeyPressed())
            _keys_queue.push_back(key);
        for (auto it = _keys_queue.begin(); it != _keys_queue.end();) {
            if (IsKeyUp(*it))
                it = _keys_queue.erase(it);
            else {
                keys_down.push_back(*it);
                it++;
            }
        }
        return (keys_down);
    }

    char Event::getCharPressed()
    {
        int c = GetCharPressed();

        if (IsKeyPressed(KEY_BACKSPACE))
            return (-1);
        else if (std::isdigit(c) || isalpha(c))
            return c;
        return (0);
    }
}
