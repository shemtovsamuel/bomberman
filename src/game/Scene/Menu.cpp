/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-samuel.shemtov
** File description:
** menu.cpp
*/

#include "Menu.hpp"

namespace IS {
    Menu::Menu(SceneManager &scene_manager, Graphics &graphics, Audio &audio, Event &event) :
        AScene(scene_manager, graphics, audio, event)
    {
        _music_path = "ressources/audio/menu_music.mp3";
        try {
            _audio.loadMusic(_music_path);
        } catch (const Error &e) {
            std::cerr << e.where() << e.what() << std::endl;
        }
        _objects.emplace_back(std::make_shared<Sprite>(Vector3(0, 0), Vector3(), Vector3(1, 1), Vector3(), "ressources/menu/bg.png", false, Vector3()));
        _objects.emplace_back(std::make_shared<Sprite>(Vector3(0, 20), Vector3(), Vector3(1, 1), Vector3(-0.15), "ressources/menu/mountains.png", true, Vector3(-9600 * 2)));
        _objects.emplace_back(std::make_shared<Sprite>(Vector3(9600 * 2, 20), Vector3(), Vector3(1, 1), Vector3(-0.15), "ressources/menu/mountains.png", true, Vector3(-9600 * 2)));
        _objects.emplace_back(std::make_shared<Sprite>(Vector3(0, 20), Vector3(), Vector3(1, 1), Vector3(-0.4), "ressources/menu/tree.png", true, Vector3(-9600 * 2)));
        _objects.emplace_back(std::make_shared<Sprite>(Vector3(9600 * 2, 20), Vector3(), Vector3(1, 1), Vector3(-0.4), "ressources/menu/tree.png", true, Vector3(-9600 * 2)));
        _objects.emplace_back(std::make_shared<Sprite>(Vector3(0, 20), Vector3(), Vector3(1, 1), Vector3(-0.85), "ressources/menu/ground.png", true, Vector3(-9600 * 2)));
        _objects.emplace_back(std::make_shared<Sprite>(Vector3(9600 * 2, 20), Vector3(), Vector3(1, 1), Vector3(-0.85), "ressources/menu/ground.png", true, Vector3(-9600 * 2)));
        _objects.emplace_back(std::make_shared<Sprite>(Vector3(0, 20), Vector3(), Vector3(1, 1), Vector3(-0.1), "ressources/menu/cloud.png", true, Vector3(-9600 * 2)));
        _objects.emplace_back(std::make_shared<Sprite>(Vector3(9600 * 2, 20), Vector3(), Vector3(1, 1), Vector3(-0.1), "ressources/menu/cloud.png", true, Vector3(-9600 * 2)));

        _objects.emplace_back(std::make_shared<Sprite>(Vector3(0, 250), Vector3(), Vector3(1, 1), Vector3(), "ressources/menu/bomb.png", false, Vector3()));
        _objects.emplace_back(std::make_shared<Sprite>(Vector3(680, 100), Vector3(), Vector3(1, 1), Vector3(), "ressources/menu/logo_bomberman.png", false, Vector3()));
        _objects.emplace_back(std::make_shared<Sprite>(Vector3(0, 0), Vector3(), Vector3(1, 1), Vector3(), "ressources/menu/title.png", false, Vector3()));

        _objects.emplace_back(std::make_shared<Button>(Vector3(1170, 500), Vector3(580, 80), Vector3(1, 1), "ressources/menu/button_jouer.png", "ressources/audio/menu_select.wav", [&](){ _scene_manager.switchTo(GAME); }));
        _objects.emplace_back(std::make_shared<Button>(Vector3(1170, 625), Vector3(580, 80), Vector3(1, 1), "ressources/menu/button_infos.png", "ressources/audio/menu_select.wav", [&](){ _scene_manager.switchTo(INFO); }));
        _objects.emplace_back(std::make_shared<Button>(Vector3(1170, 750), Vector3(580, 80), Vector3(1, 1), "ressources/menu/button_options.png", "ressources/audio/menu_select.wav", [&](){ _scene_manager.switchTo(SETTINGS); }));
        _objects.emplace_back(std::make_shared<Button>(Vector3(1170, 875), Vector3(580, 80), Vector3(1, 1), "ressources/menu/button_quitter.png", "ressources/audio/menu_select.wav", [](){ exit(0); }));
    }

    void Menu::onActivate()
    {
        _event.setKeysMonitored(getKeysMonitored());
        for (auto &obj : _objects) {
            if (obj->getIsCategory(SPRITE) || obj->getIsCategory(BUTTON)) {
                if (_graphics.getWindowSize().x == 1920)
                    obj->setScale(Vector3(1, 1));
                if (_graphics.getWindowSize().x == 1280)
                    obj->setScale(Vector3(1280 / 1920, 1280 / 1920));
                if (_graphics.getWindowSize().x == 1024)
                    obj->setScale(Vector3(1024 / 1920, 1024 / 1920));
                obj->setPosition(obj->getPosition() * obj->getScale());
                obj->setDimensions(obj->getDimensions() * obj->getScale());
            }
        }
    }

    void Menu::onDeactivate()
    {
        _audio.stopMusic(_music_path);
    }

    void Menu::update()
    {
        // _graphics.updateCamera();
        _audio.playUpdateMusic(_music_path);
        for (auto &obj : _objects)
            if (obj->getIsCategory(MOVABLE)) {
                auto movable = std::dynamic_pointer_cast<Movable>(obj);
                if (obj->getSpeed() != Vector3()) {
                    obj->setPosition(obj->getPosition() + obj->getSpeed());
                    if (obj->getIsCategory(SPRITE)) {
                        auto sprite = std::dynamic_pointer_cast<Sprite>(movable);
                        if (sprite->getReset() && (sprite->getSpeed().x < 0 && sprite->getPosition().x <= sprite->getEndPos().x) ||
                            (sprite->getSpeed().x > 0 && sprite->getPosition().x >= sprite->getEndPos().x) ||
                            (sprite->getSpeed().y < 0 && sprite->getPosition().y <= sprite->getEndPos().y) ||
                            (sprite->getSpeed().y > 0 && sprite->getPosition().y >= sprite->getEndPos().y))
                            sprite->setPosition(sprite->getInitPos());
                    }
                }
            }
    }
}
