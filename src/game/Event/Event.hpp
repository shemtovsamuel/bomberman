/*
** EPITECH PROJECT, 2022
** Event.hpp
** File description:
** Event
*/

#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <memory>
#include "../Type/Type.hpp"

namespace IS {
    class TextField;

    class Event {
        public:
            Event();
            ~Event() = default;

            bool isMouseButtonLeftPressed();
            bool isMouseButtonLeftDown();
            bool isMouseButtonLeftReleased();
            Vector2 getMousePosition();
            bool checkCollisionPointRec(Vector2 point, Rectangle rec); // do rectangle encap
            bool isCursorInRange(Rectangle rec);
            void setKeysMonitored(std::vector<int> keys_monitored);
            int getKeyPressed();
            std::vector<int> getKeysDown();
            char getCharPressed();
        protected:
        private:
            std::vector<int> _keys_repertory;
            std::vector<int> _keys_monitored;
            std::vector<int> _keys_queue;
    };
}

#endif /* !EVENT_HPP_ */
