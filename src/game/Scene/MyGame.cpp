/*
** EPITECH PROJECT, 2022
** indiestudio
** File description:
** MyGame.cpp
*/

#include "MyGame.hpp"

namespace IS {
    Game::Game(SceneManager &scene_manager, Graphics &graphics, Audio &audio, Event &event) :
        AScene(scene_manager, graphics, audio, event),
        _map(std::make_unique<Map>(_scene_manager.getMapSize()))
    {
        _music_path = "ressources/audio/menu_music.mp3";
        try {
            _graphics.loadTexture("ressources/3D/Player1.png");
            _graphics.loadTexture("ressources/3D/Player4.png");
            _graphics.loadModel("ressources/3D/PlayerModelWalk.iqm");
            _graphics.setMaterialTexture("ressources/3D/PlayerModelWalk.iqm", "ressources/3D/Player1.png");
        } catch (const Error &e) {

        }
        _objects.emplace_back(std::make_shared<Player>(Vector3(), Vector3(0.0033, 0.0025, 0.0033), Vector3(1, 1, 1), Vector3(), 0, "ressources/3D/Player1.png"), "ressources/3D/PlayerModelWalk.iqm", "ressources/3D/PlayerAnimWalk.iqm");
    }

    void Game::onActivate()
    {
        initMapObjects();
        std::vector<Vector3> player_pos;
        _graphics.createCamera(Vector3(0, _map->getSize() + _map->getSize() / 4, _map->getSize() / 3), Vector3(0, 0, 2), Vector3(0, 1, 0));
        for (int i = 0, j = 0; j < MAX_PLAYERS; i++) {
            if (_objects[i]->getIsCategory(PLAYER)) {
                auto player = std::dynamic_pointer_cast<Player>(_objects[i]);
                player->setPosition(player_pos[j]);
                j++;
            }
        }
    }

    void Game::onDeactivate()
    {
        _audio.stopMusic(_music_path);
        _objects.erase(_objects.end() - _map->getSize(), _objects.end());
    }

    void Game::update()
    {
        _graphics.updateCamera();
        _audio.playUpdateMusic(_music_path);
        for (auto &obj : _objects) {
            if (obj->getIsCategory(PLAYER)) {
                auto player = std::dynamic_pointer_cast<Player>(obj);
                player->update();
            }
        }
    }

    void Game::initMapObjects()
    {
        _map->generationIteration();
        std::vector<std::vector<std::shared_ptr<AObject>>> blocks = _map->getBlocks();
        for (int z = 0; z < _map->getSize(); z++) {
            for (int x = 0; z < _map->getSize(); z++) {
                _objects.push_back(blocks[z][x]);
            }
        }
    }
}
