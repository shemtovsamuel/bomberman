/*
** EPITECH PROJECT, 2022
** myGame
** File description:
** MyGame
*/

#ifndef MYGAME_HPP_
#define MYGAME_HPP_

#include "AScene.hpp"
#include "../Map/MyMap.hpp"

namespace IS {
    class Game : public AScene {
        public:
            Game(SceneManager &scene_manager, Graphics &graphics, Audio &audio, Event &event);
            ~Game() = default;
            void onActivate();
            void onDeactivate();
            void update();
            void initMapObjects();
        protected:
            std::unique_ptr<Map> _map;
        private:
    };
}

#endif /* !MYGAME_HPP_ */
