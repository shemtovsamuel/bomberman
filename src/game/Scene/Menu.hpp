/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-samuel.shemtov
** File description:
** menu.hpp
*/

#pragma once

#include "AScene.hpp"

namespace IS {
    class Menu : public AScene {
        public:
            Menu(SceneManager &scene_manager, Graphics &graphics, Audio &audio, Event &event);
            ~Menu() = default;
            void onActivate() override;
            void onDeactivate() override;
            void update() override;

        protected:
        private:
    };
}
