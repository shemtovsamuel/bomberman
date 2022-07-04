/*
** EPITECH PROJECT, 2022
** Toggle.hpp
** File description:
** Toggle
*/

#ifndef TOGGLE_HPP_
#define TOGGLE_HPP_

#include <functional>
#include "../Ui.hpp"
#include "../../../Graphics/Graphics.hpp"
#include "../../../Audio/Audio.hpp"

namespace IS {
    class Toggle : public Ui {
        public:
            Toggle(const Vector3 &position, const Vector3 &dimensions, const Vector3 &scale, const std::pair<std::string, std::string> &state_texture_paths, const bool &active, const float &frame_height, const Rectangle &texture_rec, const std::string &sound_path, const std::function<void()> &callback);
            ~Toggle() = default;
            bool getActive();
            void setActive(bool active);
            void changeActive();
            Rectangle getTextureRec();
            void setTextureRec(const state_e &state);
            void setCallback(std::function<void()> callback);
            void triggerToggle(Audio &audio, Event &event);

        protected:
            std::pair<std::string, std::string> _state_texture_paths;
            bool _active;
            float _frame_height;
            Rectangle _texture_rec;
            std::string _sound_path;
            std::function<void()> _callback;
        private:
    };
}

#endif /* !TOGGLE_HPP_ */
