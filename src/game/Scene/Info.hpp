/*
** EPITECH PROJECT, 2022
** Info.hpp
** File description:
** Info
*/

#ifndef INFO_HPP_
#define INFO_HPP_

#include "AScene.hpp"

namespace IS {
    class Info : public AScene {
        public:
            Info(SceneManager &scene_manager, Graphics &graphics, Audio &audio, Event &event);
            ~Info() = default;
            void onActivate() override;
            void onDeactivate() override;
            void update() override;

        protected:
        private:
    };
}

#endif /* !INFO_HPP_ */
