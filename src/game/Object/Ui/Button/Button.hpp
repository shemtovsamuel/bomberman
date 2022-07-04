/*
** EPITECH PROJECT, 2022
** Button.hpp
** File description:
** Button
*/

#pragma once

#include <functional>
#include "../Ui.hpp"
#include "../../../Audio/Audio.hpp"
#include "../../../Event/Event.hpp"

namespace IS {
    class TextField;

    class Button : public Ui {
        public:
            Button(const Vector3 &position, const Vector3 &dimensions, const Vector3 &scale, const std::string &texture_path, const std::string &sound_path, const std::function<void()> &callback);
            ~Button() = default;
            Rectangle getTextureRec();
            void setTextureRec(const state_e &state);
            void setCallback(std::function<void()> callback);
            void triggerButton(Audio &audio, Event &event, std::shared_ptr<Button> button);

        protected:
            float _frame_height;
            Rectangle _texture_rec;
            std::string _sound_path;
            std::function<void()> _callback;
        private:
    };
}
