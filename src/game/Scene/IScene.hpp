/*
** EPITECH PROJECT, 2022
** IScene.hpp
** File description:
** IScene
*/

#ifndef ISCENE_HPP_
#define ISCENE_HPP_

#include <functional>
#include <vector>

namespace IS {
    enum key_e {
            A,
            B,
            C,
            D,
            E,
            F,
            G,
            H,
            I,
            J,
            K,
            L,
            M,
            N,
            O,
            P,
            Q,
            R,
            S,
            T,
            U,
            V,
            W,
            X,
            Y,
            Z,
            SPACE,
            ENTER,
            BACKSPACE,
            RIGHT,
            LEFT,
            DOWN,
            UP
    };

    enum sceneId_e {
        NONE = 0,
        SPLASH_SCREEN,
        MENU,
        INFO,
        SETTINGS,
        GAME,
        RANKING,
    };

    class IScene {
        public:
            virtual ~IScene() = default;
            virtual void onActivate() = 0;
            virtual void onDeactivate() = 0;
            virtual void processInput() = 0;
            virtual void update() = 0;
            virtual void draw() = 0;
            virtual std::vector<int> getKeysMonitored() = 0;
            virtual void setKeyMonitored(key_e key, std::function<void()> callback) = 0;

        protected:
        private:
    };
}

#endif /* !ISCENE_HPP_ */
