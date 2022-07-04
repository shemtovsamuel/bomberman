/*
** EPITECH PROJECT, 2022
** Info.cpp
** File description:
** Info
*/

#include "Info.hpp"

namespace IS {
    Info::Info(SceneManager &scene_manager, Graphics &graphics, Audio &audio, Event &event) :
        AScene(scene_manager, graphics, audio, event)
    {
        _music_path = "ressources/audio/menu_music.mp3";
        _objects.emplace_back(std::make_shared<Sprite>(Vector3(0, 0), Vector3(), Vector3(1, 1), Vector3(), "ressources/menu/bg.png", false, Vector3()));
        _objects.emplace_back(std::make_shared<Sprite>(Vector3(0, 20), Vector3(), Vector3(1, 1), Vector3(-0.15), "ressources/menu/mountains.png", true, Vector3(-9600 * 2)));
        _objects.emplace_back(std::make_shared<Sprite>(Vector3(9600 * 2, 20), Vector3(), Vector3(1, 1), Vector3(-0.15), "ressources/menu/mountains.png", true, Vector3(-9600 * 2)));
        _objects.emplace_back(std::make_shared<Sprite>(Vector3(0, 20), Vector3(), Vector3(1, 1), Vector3(-0.4), "ressources/menu/tree.png", true, Vector3(-9600 * 2)));
        _objects.emplace_back(std::make_shared<Sprite>(Vector3(9600 * 2, 20), Vector3(), Vector3(1, 1), Vector3(-0.4), "ressources/menu/tree.png", true, Vector3(-9600 * 2)));
        _objects.emplace_back(std::make_shared<Sprite>(Vector3(0, 20), Vector3(), Vector3(1, 1), Vector3(-0.85), "ressources/menu/ground.png", true, Vector3(-9600 * 2)));
        _objects.emplace_back(std::make_shared<Sprite>(Vector3(9600 * 2, 20), Vector3(), Vector3(1, 1), Vector3(-0.85), "ressources/menu/ground.png", true, Vector3(-9600 * 2)));
        _objects.emplace_back(std::make_shared<Sprite>(Vector3(0, 20), Vector3(), Vector3(1, 1), Vector3(-0.1), "ressources/menu/cloud.png", true, Vector3(-9600 * 2)));
        _objects.emplace_back(std::make_shared<Sprite>(Vector3(9600 * 2, 20), Vector3(), Vector3(1, 1), Vector3(-0.1), "ressources/menu/cloud.png", true, Vector3(-9600 * 2)));

        _objects.emplace_back(std::make_shared<Sprite>(Vector3(0, 0), Vector3(), Vector3(1, 1), Vector3(), "ressources/settings/info.png", false, Vector3()));

        _objects.emplace_back(std::make_shared<Button>(Vector3(1536, 36), Vector3(348, 48), Vector3(1, 1), "ressources/settings/button_menu.png", "ressources/audio/menu_select.wav", [&](){ _scene_manager.switchTo(MENU); }));
    }

    void Info::onActivate()
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

    void Info::onDeactivate()
    {
        _audio.stopMusic(_music_path);
    }

    void Info::update()
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
