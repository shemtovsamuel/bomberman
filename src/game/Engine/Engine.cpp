/*
** EPITECH PROJECT, 2022
** Engine.cpp
** File description:
** Engine
*/

#include "Engine.hpp"

namespace IS {
    Engine::Engine() :
        _graphics(),
        _audio(),
        _event(),
        _scene_manager(_graphics, _audio, _event)
    {
        _graphics.loadFont("ressources/font/Righteous-Regular.ttf");
        _scene_manager.add(MENU, std::make_shared<Menu>(_scene_manager, _graphics, _audio, _event));
        _scene_manager.switchTo(MENU);
        _scene_manager.add(INFO, std::make_shared<Info>(_scene_manager, _graphics, _audio, _event));
        _scene_manager.add(SETTINGS, std::make_shared<Settings>(_scene_manager, _graphics, _audio, _event));
        _scene_manager.add(GAME, std::make_shared<Game>(_scene_manager, _graphics, _audio, _event));
        // _scenes.insert({RANKING, std::make_shared<Ranking>()});
    }

    void Engine::run()
    {
        while (_graphics.isWindowOpened()) {
            _scene_manager.processInput();
            _scene_manager.update();
            _scene_manager.draw();
        }
    }
}