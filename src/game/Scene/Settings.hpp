/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-samuel.shemtov
** File description:
** Settings.hpp
*/

#pragma once

// #include "Global.hpp"
// #include <iostream>
// #include "raylib.h"
// #include "raymath.h"
// #include <vector>
// #include "../src/game/Object/Ui/Button/Button.hpp"
// 
// class Settings {
    // public:
        // Settings(int screenWidth, int screenHeight);
        // ~Settings();
        // void updateSettings();
        // void drawSettings();
        // void conditionBtn();
// 
    // private:
        // int _screenWidth;
        // int _screenHeight;
        // Vector2 _mousePoint;
        // float _scale;
        // Texture2D _layer_settings;
        // Button _buttonMenu;
        // Button _button1;
        // Button _button2;
        // Button _button3;
        // Button _button4;
        // Button _buttonOnOff;
        // Button _button1920;
        // Button _button1280;
        // Button _button1024;
        // Button _buttonPetite;
        // Button _buttonMoyenne;
        // Button _buttonGrande;
// };

#include "AScene.hpp"

namespace IS {
    class Settings : public AScene {
        public:
            Settings(SceneManager &scene_manager, Graphics &graphics, Audio &audio, Event &event);
            ~Settings() = default;
            void onActivate() override;
            void onDeactivate() override;
            void update() override;

        protected:
        private:
    };
}
