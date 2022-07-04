/*
** EPITECH PROJECT, 2022
** MyMenu.cpp
** File description:
** MyMenu
*/

#include "MyMenu.hpp"

namespace IS {
    Menu::Menu(SceneManager &scene_manager, Graphics &graphics, Audio &audio, Event &event) :
        AScene(scene_manager, graphics, audio, event)
    {
        try {
            _graphics.loadTexture("ressources/menu/bg.png");
            _graphics.loadTexture("ressources/menu/mountains.png");
            _graphics.loadTexture("ressources/menu/tree.png");
            _graphics.loadTexture("ressources/menu/ground.png");
            _graphics.loadTexture("ressources/menu/cloud.png");

            _graphics.loadTexture("ressources/menu/bomb.png");
            _graphics.loadTexture("ressources/menu/title.png");

            _graphics.loadTexture("ressources/menu/button_jouer.png");
            _graphics.loadTexture("ressources/menu/button_infos.png");
            _graphics.loadTexture("ressources/menu/button_options.png");
            _graphics.loadTexture("ressources/menu/button_quitter.png");

            _audio.loadMusic("ressources/audio/menu_music.mp3");
            _audio.loadSound("ressources/audio/menu_select.wav");
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

        _objects.emplace_back(std::make_shared<Sprite>(Vector3(0, 0), Vector3(), Vector3(1, 1), Vector3(), "ressources/menu/bomb.png", false, Vector3()));
        _objects.emplace_back(std::make_shared<Sprite>(Vector3(0, 0), Vector3(), Vector3(1, 1), Vector3(), "ressources/menu/title.png", false, Vector3()));

        _objects.emplace_back(std::make_shared<Button>(Vector3(1170, 500, 0), Vector3(580, 80), Vector3(1, 1), "ressources/menu/button_jouer.png", 80, Rectangle(0, 0, 580, 80), "ressources/audio/menu_select.wav", [](){}));
        _objects.emplace_back(std::make_shared<Button>(Vector3(1170, 625, 0), Vector3(580, 80), Vector3(1, 1), "ressources/menu/button_infos.png", 80, Rectangle(0, 0, 580, 80), "ressources/audio/menu_select.wav", [](){}));
        _objects.emplace_back(std::make_shared<Button>(Vector3(1170, 750, 0), Vector3(580, 80), Vector3(1, 1), "ressources/menu/button_options.png", 80, Rectangle(0, 0, 580, 80), "ressources/audio/menu_select.wav", [](){}));
        _objects.emplace_back(std::make_shared<Button>(Vector3(1170, 875, 0), Vector3(580, 80), Vector3(1, 1), "ressources/menu/button_quitter.png", 80, Rectangle(0, 0, 580, 80), "ressources/audio/menu_select.wav", [](){}));
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
                obj->setPosition(obj->getPosition() * obj->getScale() / 1920);
                obj->setDimensions(obj->getDimensions() * obj->getScale() / 1920);
            }
        }
        _audio.playMusic("ressources/audio/menu_music.mp3");
    }

    void Menu::onDeactivate()
    {
        _audio.stopMusic("ressources/audio/menu_music.mp3");
    }

    void Menu::update()
    {
        for (auto &obj : _objects)
            if (obj->getIsCategory(MOVABLE)) {
                auto movable = std::dynamic_pointer_cast<Movable>(obj);
                if (obj->getSpeed() != Vector3()) {
                    obj->setPosition(obj->getPosition() + obj->getSpeed());
                    if (obj->getIsCategory(SPRITE)) {
                        auto sprite = std::dynamic_pointer_cast<Sprite>(movable);
                        if (sprite->getPosition().x <= sprite->getEndPos().x)
                            sprite->setPosition(sprite->getInitPos());
                    }
                }
            }
    }
}
