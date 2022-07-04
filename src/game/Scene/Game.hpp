/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-samuel.shemtov
** File description:
** game.hpp
*/

#pragma once

#include "Global.hpp"
#include "../Map/Map.hpp"
#include "../Object/Model3d/Player/Player.hpp"
#include <iostream>
#include "raylib.h"
#include "raymath.h"
#include <vector>
#include "../Graphics/Graphics.hpp"
#include "../Graphics/window.hpp"
#include "../Audio/Audio.hpp"
#include "AScene.hpp"

class Game : public IS::AScene {
    public:
        Game(IS::SceneManager &scene_manager, IS::Graphics &graphics, IS::Audio &audio, IS::Event &event);
        ~Game();

        void onActivate();
        void onDeactivate();
        void processInput();
        void update();

        // Camera getCamera();
        // void setCamera(Camera camera);
        Map getMap();
        void setMap(Map map);
        std::vector<Player> getPlayers();
        void setPlayers();
        int getNbAlive();
        void updateNbAlive();
        int getLastPlayerId();
        bool endGame();
        void setPlayer(Player player);
        void updateGame();
        void drawGame();
        void runGame();

    private:
        Map _map;
        std::vector<Player> _players;
        std::vector<int> _screenSize;
        Texture2D _background;
        int _nb_alive;
};
