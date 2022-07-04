/*
** EPITECH PROJECT, 2022
** SceneManager.hpp
** File description:
** SceneManager
*/

#ifndef SCENEMANAGER_HPP_
#define SCENEMANAGER_HPP_

#include <unordered_map>
#include "../Graphics/Graphics.hpp"
#include "../Audio/Audio.hpp"
#include "../Event/Event.hpp"
#include "IScene.hpp"

namespace IS {
    class SceneManager {
        public:
            SceneManager(Graphics &graphics, Audio &audio, Event &event);
            ~SceneManager();
            void processInput();
            void update();
            void draw();
            void add(sceneId_e scene_id, std::shared_ptr<IScene> scene);
            void switchTo(sceneId_e scene_id);
            void remove(sceneId_e scene_id);
            int getMapSize();
            void setMapSize(const int &map_size);
            int getNbHumans();
            void setNbHumans(const int &nb_humans);

        protected:
        private:
            Graphics  &_graphics;
            Audio &_audio;
            Event &_event;
            std::unordered_map<sceneId_e, std::shared_ptr<IScene>> _scenes;
            std::shared_ptr<IScene> _cur_scene;
            int _map_size;
            int _nb_humans;

    };
}

#endif /* !SCENEMANAGER_HPP_ */
