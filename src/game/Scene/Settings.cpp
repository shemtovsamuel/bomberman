/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-samuel.shemtov
** File description:
** Settings.cpp
*/

#include "Settings.hpp"
#define NUMFRAME 3

// Settings::Settings(int screenWidth, int screenHeight) : _screenWidth(screenWidth), _screenHeight(screenHeight),
    // _buttonMenu(screenWidth, screenHeight, -620, 300, "ressources/settings/button_menu.png"),
    // _button1(screenWidth, screenHeight, -35, -290, "ressources/settings/button_1.png"),
    // _button2(screenWidth, screenHeight, 223, -290, "ressources/settings/button_2.png"),
    // _button3(screenWidth, screenHeight, 481, -290, "ressources/settings/button_3.png"),
    // _button4(screenWidth, screenHeight, 739, -290, "ressources/settings/button_4.png"),
    // _buttonOnOff(screenWidth, screenHeight, 25, 120, "ressources/settings/button_ON_OFF.png"),
    // _button1920(screenWidth, screenHeight, 25, 330, "ressources/settings/button_1920x1080.png"),
    // _button1280(screenWidth, screenHeight, 390, 330, "ressources/settings/button_1280x720.png"),
    // _button1024(screenWidth, screenHeight, 760, 330, "ressources/settings/button_1024x576.png"),
    // _buttonPetite(screenWidth, screenHeight, 25, -85, "ressources/settings/button_petite.png"),
    // _buttonMoyenne(screenWidth, screenHeight, 390, -85, "ressources/settings/button_moyenne.png"),
    // _buttonGrande(screenWidth, screenHeight, 760, -85, "ressources/settings/button_grande.png")
// {
    // _scale = 1.0f;
    // if (_screenWidth == 1280)
        // _scale = 0.66666666666;
    // else if (_screenWidth == 1024)
        // _scale = 0.53333333333;
// 
    // _mousePoint = GetMousePosition();
    // _layer_settings = LoadTexture("ressources/settings/layer_settings.png");
// }

// // void Settings::conditionBtn() {
// //     if (_button1920.getBtnAction()) {
// //         SCREEN_WIDTH = 1920;
// //         SCREEN_HEIGHT = 1080;
// //         SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
// //     }
// //     if (_button1280.getBtnAction()) {
// //         SCREEN_WIDTH = 1280;
// //         SCREEN_HEIGHT = 720;
// //         SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
// //     }
// //     if (_button1024.getBtnAction()) {
// //         SCREEN_WIDTH = 1024;
// //         SCREEN_HEIGHT = 576;
// //         SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
// //     }
// // }

// void Settings::updateSettings()
// {
    // // conditionBtn();
    // _mousePoint = GetMousePosition();
    // _buttonMenu.updateButton(_mousePoint);
    // _button1.updateButton(_mousePoint);
    // _button2.updateButton(_mousePoint);
    // _button3.updateButton(_mousePoint);
    // _button4.updateButton(_mousePoint);
    // _buttonOnOff.updateButton(_mousePoint);
    // _button1920.updateButton(_mousePoint);
    // _button1280.updateButton(_mousePoint);
    // _button1024.updateButton(_mousePoint);
    // _buttonPetite.updateButton(_mousePoint);
    // _buttonMoyenne.updateButton(_mousePoint);
    // _buttonGrande.updateButton(_mousePoint);
// }
// 
// void Settings::drawSettings()
// {
    // DrawTextureEx(_layer_settings, (Vector2){0}, 0.0f, _scale, WHITE);
    // _buttonMenu.drawButton();
    // _button1.drawButton();
    // _button2.drawButton();
    // _button3.drawButton();
    // _button4.drawButton();
    // _buttonOnOff.drawButton();
    // _button1920.drawButton();
    // _button1280.drawButton();
    // _button1024.drawButton();
    // _buttonPetite.drawButton();
    // _buttonMoyenne.drawButton();
    // _buttonGrande.drawButton();
// }
// 
// Settings::~Settings()
// {
    // UnloadTexture(_layer_settings);
// }

namespace IS {
    Settings::Settings(SceneManager &scene_manager, Graphics &graphics, Audio &audio, Event &event) :
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

        _objects.emplace_back(std::make_shared<Sprite>(Vector3(0, 0), Vector3(), Vector3(1, 1), Vector3(), "ressources/settings/layer_settings.png", false, Vector3()));

        _objects.emplace_back(std::make_shared<Button>(Vector3(_graphics.getWindowSize().x / 2 - 348 / 2 - 620, _graphics.getWindowSize().y / 2 - (144 / 3) / NUMFRAME / 2 + 300, 0), Vector3(348, 144 / 3), Vector3(1, 1), "ressources/settings/button_menu.png", "ressources/audio/menu_select.wav", [&](){ _scene_manager.switchTo(MENU); }));
        _objects.emplace_back(std::make_shared<Button>(Vector3(_graphics.getWindowSize().x / 2 - 228 / 2 - 35, _graphics.getWindowSize().y / 2 - (144 / 3) / NUMFRAME / 2 - 290, 0), Vector3(228, 144 / 3), Vector3(1, 1), "ressources/settings/button_1.png", "ressources/audio/menu_select.wav", [&](){ _scene_manager.setNbHumans(1); }));
        _objects.emplace_back(std::make_shared<Button>(Vector3(_graphics.getWindowSize().x / 2 - 228 / 2 + 223, _graphics.getWindowSize().y / 2 - (144 / 3) / NUMFRAME / 2 - 290, 0), Vector3(228, 144 / 3), Vector3(1, 1), "ressources/settings/button_2.png", "ressources/audio/menu_select.wav", [&](){ _scene_manager.setNbHumans(2); }));
        _objects.emplace_back(std::make_shared<Button>(Vector3(_graphics.getWindowSize().x / 2 - 228 / 2 + 481, _graphics.getWindowSize().y / 2 - (144 / 3) / NUMFRAME / 2 - 290, 0), Vector3(228, 144 / 3), Vector3(1, 1), "ressources/settings/button_3.png", "ressources/audio/menu_select.wav", [&](){ _scene_manager.setNbHumans(3); }));
        _objects.emplace_back(std::make_shared<Button>(Vector3(_graphics.getWindowSize().x / 2 - 228 / 2 + 739, _graphics.getWindowSize().y / 2 - (144 / 3) / NUMFRAME / 2 - 290, 0), Vector3(228, 144 / 3), Vector3(1, 1), "ressources/settings/button_4.png", "ressources/audio/menu_select.wav", [&](){ _scene_manager.setNbHumans(4); }));
        _objects.emplace_back(std::make_shared<Button>(Vector3(_graphics.getWindowSize().x / 2 - 348 / 2 + 25, _graphics.getWindowSize().y / 2 - (144 / 3) / NUMFRAME / 2 + 120, 0), Vector3(348, 144 / 3), Vector3(1, 1), "ressources/settings/button_ON_OFF.png", "ressources/audio/menu_select.wav", [&](){ _audio.changeMusicState(); }));
        _objects.emplace_back(std::make_shared<Button>(Vector3(_graphics.getWindowSize().x / 2 - 348 / 2 + 25, _graphics.getWindowSize().y / 2 - (144 / 3) / NUMFRAME / 2 + 330, 0), Vector3(348, 144 / 3), Vector3(1, 1), "ressources/settings/button_1920x1080.png", "ressources/audio/menu_select.wav", [&](){ /*_graphics.setWindowSize(Vector2(1920, 1080)); onActivate();*/ }));
        _objects.emplace_back(std::make_shared<Button>(Vector3(_graphics.getWindowSize().x / 2 - 348 / 2 + 390, _graphics.getWindowSize().y / 2 - (144 / 3) / NUMFRAME / 2 + 330, 0), Vector3(348, 144 / 3), Vector3(1, 1), "ressources/settings/button_1280x720.png", "ressources/audio/menu_select.wav", [&](){ /*_graphics.setWindowSize(Vector2(1280, 720)); onActivate();*/ }));
        _objects.emplace_back(std::make_shared<Button>(Vector3(_graphics.getWindowSize().x / 2 - 348 / 2 + 760, _graphics.getWindowSize().y / 2 - (144 / 3) / NUMFRAME / 2 + 330, 0), Vector3(348, 144 / 3), Vector3(1, 1), "ressources/settings/button_1024x576.png", "ressources/audio/menu_select.wav", [&](){ /*_graphics.setWindowSize(Vector2(1024, 576)); onActivate();*/ }));
        _objects.emplace_back(std::make_shared<Button>(Vector3(_graphics.getWindowSize().x / 2 - 348 / 2 + 25, _graphics.getWindowSize().y / 2 - (144 / 3) / NUMFRAME / 2 - 85, 0), Vector3(348, 144 / 3), Vector3(1, 1), "ressources/settings/button_petite.png", "ressources/audio/menu_select.wav", [&](){ _scene_manager.setMapSize(30); }));
        _objects.emplace_back(std::make_shared<Button>(Vector3(_graphics.getWindowSize().x / 2 - 348 / 2 + 390, _graphics.getWindowSize().y / 2 - (144 / 3) / NUMFRAME / 2 - 85, 0), Vector3(348, 144 / 3), Vector3(1, 1), "ressources/settings/button_moyenne.png", "ressources/audio/menu_select.wav", [&](){ _scene_manager.setMapSize(40); }));
        _objects.emplace_back(std::make_shared<Button>(Vector3(_graphics.getWindowSize().x / 2 - 348 / 2 + 760, _graphics.getWindowSize().y / 2 - (144 / 3) / NUMFRAME / 2 - 85, 0), Vector3(348, 144 / 3), Vector3(1, 1), "ressources/settings/button_grande.png", "ressources/audio/menu_select.wav", [&](){ _scene_manager.setMapSize(50); }));
    }

    void Settings::onActivate()
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

    void Settings::onDeactivate()
    {
        _audio.stopMusic(_music_path);
    }

    void Settings::update()
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
