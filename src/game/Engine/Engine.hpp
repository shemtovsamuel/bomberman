#pragma once

#include "../Graphics/Graphics.hpp"
#include "../Audio/Audio.hpp"
#include "../Event/Event.hpp"
#include "../Scene/SceneManager.hpp"
#include "../Scene/Menu.hpp"
#include "../Scene/Info.hpp"
#include "../Scene/Settings.hpp"
#include "../Scene/Game.hpp"

namespace IS {
    class Engine {
        public:
            Engine();
            ~Engine() = default;
            void run();

        protected:
        private:
            Graphics _graphics;
            Audio _audio;
            Event _event;
            SceneManager _scene_manager;
    };
}