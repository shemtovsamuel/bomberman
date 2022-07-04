/*
** EPITECH PROJECT, 2022
** SceneManager.cpp
** File description:
** SceneManager
*/

#include "SceneManager.hpp"

namespace IS {
    SceneManager::SceneManager(Graphics &graphics, Audio &audio, Event &event) :
        _graphics(graphics),
        _audio(audio),
        _event(event),
        _scenes({}),
        _cur_scene(nullptr),
        _map_size(SMALL),
        _nb_humans(SOLO)
    {
    }

    SceneManager::~SceneManager()
    {
        _scenes.clear();
    }

    void SceneManager::processInput()
    {
        if (_cur_scene)
            _cur_scene->processInput();
    }

    void SceneManager::update()
    {
        if (_cur_scene)
            _cur_scene->update();
    }

    void SceneManager::draw()
    {
        if (_cur_scene)
            _cur_scene->draw();
    }

    void SceneManager::add(sceneId_e scene_id, std::shared_ptr<IScene> scene)
    {
        _scenes.insert({scene_id, scene});
    }

    void SceneManager::switchTo(sceneId_e scene_id)
    {
        auto it = _scenes.find(scene_id);
    
        if (it != _scenes.end()) {
            if (_cur_scene)
                _cur_scene->onDeactivate();
            _cur_scene = it->second;
            _cur_scene->onActivate();
        }
    }

    void SceneManager::remove(sceneId_e scene_id)
    {
        auto it = _scenes.find(scene_id);

        if (it != _scenes.end()) {
            if (_cur_scene)
                _cur_scene = nullptr;
            _scenes.erase(it);
        }
    }

    int SceneManager::getMapSize()
    {
        return _map_size;
    }

    void SceneManager::setMapSize(const int &map_size)
    {
        _map_size = map_size;
    }

    int SceneManager::getNbHumans()
    {
        return _nb_humans;
    }

    void SceneManager::setNbHumans(const int &nb_humans)
    {
        _nb_humans = nb_humans;
    }
}
