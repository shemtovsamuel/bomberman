/*
** EPITECH PROJECT, 2022
** MyMenu.hpp
** File description:
** MyMenu
*/

#ifndef MYMENU_HPP_
#define MYMENU_HPP_

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

#endif /* !MYMENU_HPP_ */
