/*
** EPITECH PROJECT, 2022
** AScene.hpp
** File description:
** AScene
*/

#ifndef ASCENE_HPP_
#define ASCENE_HPP_

#include "IScene.hpp"
#include "SceneManager.hpp"
#include "../Graphics/Graphics.hpp"
#include "../Audio/Audio.hpp"
#include "../Event/Event.hpp"
#include "../Object/Model3d/Player/Player.hpp"
#include "../Object/Ui/Button/Button.hpp"
#include "../Object/Ui/Button/TextField/TextField.hpp"
#include "../Object/Ui/Movable/Sprite/Sprite.hpp"
#include "../Object/Ui/Movable/Text/Text.hpp"
#include "../Object/Ui/Toggle/Toggle.hpp"

namespace IS {
    class AScene : public IScene {
        public:
            AScene(SceneManager &scene_manager, Graphics &graphics, Audio &audio, Event &event);
            ~AScene();
            virtual void onActivate() = 0;
            virtual void onDeactivate() = 0;
            void processInput();
            virtual void update();
            void draw();
            std::vector<int> getKeysMonitored();
            void setKeyMonitored(key_e key, std::function<void()> callback);
        protected:
            SceneManager &_scene_manager;
            Graphics &_graphics;
            Audio &_audio;
            Event &_event;
            std::string _music_path;
            std::vector<std::shared_ptr<AObject>> _objects;
            std::shared_ptr<TextField> _text_field;
            std::unordered_map<int, std::function<void()>> _keys_monitored;
        private:
    };
}

#endif /* !ASCENE_HPP_ */
