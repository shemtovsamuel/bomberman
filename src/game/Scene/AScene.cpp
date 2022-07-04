/*
** EPITECH PROJECT, 2022
** AScene.cpp
** File description:
** AScene
*/

#include "AScene.hpp"

namespace IS {
    AScene::AScene(SceneManager &scene_manager, Graphics &graphics, Audio &audio, Event &event) :
        _scene_manager(scene_manager),
        _graphics(graphics),
        _audio(audio),
        _event(event),
        _objects({}),
        _text_field(nullptr),
        _keys_monitored({})
    {
    }

    AScene::~AScene()
    {
        _objects.clear();
    }

    void AScene::processInput()
    {
        for (auto &obj : _objects) {
            if (obj->getIsCategory(BUTTON)) {
                auto button = std::dynamic_pointer_cast<Button>(obj);
                button->triggerButton(_audio, _event, button);
                if (button->getIsCategory(TEXT_FIELD)) {
                    if (_text_field != nullptr)
                        _text_field->popMarker();
                    _text_field = std::dynamic_pointer_cast<TextField>(button);
                    _text_field->appendMarker();
                }
            } else {
                if (_event.isMouseButtonLeftReleased()) {
                    if (_text_field != nullptr)
                        _text_field->popMarker();
                    _text_field = nullptr;
                }
                if (obj->getIsCategory(TOGGLE)) {
                    auto toggle = std::dynamic_pointer_cast<Toggle>(obj);
                    toggle->triggerToggle(_audio, _event);
                }
            }
        }
        if (_text_field) {
            _text_field->setTextureRec(CLICKED);
            _text_field->replaceLast(_event.getCharPressed());
        } else {
            for (const auto &key : _event.getKeysDown())
                _keys_monitored[key]();
        }
    }

    void AScene::update()
    {
    }

    void AScene::draw()
    {
        _graphics.setWindowSize(_graphics.getWindowSize());
        _graphics.beginDrawing();
        _graphics.clearBackground();
        for (const auto &obj : _objects) {
            if (obj->getIsCategory(MODEL_3D)) {
                _graphics.beginMode3d();
                _graphics.drawModel3d(obj);
                _graphics.endMode3d();
            } else
                _graphics.drawUi(obj);
        }
        _graphics.endDrawing();
    }

    std::vector<int> AScene::getKeysMonitored()
    {
        std::vector<int> keys_monitored = {};
    
        for (const auto &key : _keys_monitored)
            keys_monitored.push_back(key.first);
        return keys_monitored;
    }

    void AScene::setKeyMonitored(key_e key, std::function<void()> callback)
    {
        auto it = _keys_monitored.find(key);

        if (it != _keys_monitored.end())
            it->second = callback;
        else
            _keys_monitored.insert({key, callback});
    }
}
