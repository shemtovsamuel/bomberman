/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-samuel.shemtov
** File description:
** PLayer.hpp
*/

#pragma once

#include "Bomb/Bomb.hpp"
#include <iostream>
#include "raylib.h"
#include "raymath.h"
#include <vector>
#include <memory>

class Player {
    public:
        Player(int id, IS::pos coords, IS::pos size, int nb_bomb);
        ~Player();
        Model getModel();
        IS::pos getPosition();
        IS::pos getPrevPosition();
        IS::pos getSize();
        float getSpeed();
        int getNbBomb();
        int getBombRange();
        std::array<int, 5> getControls();
        std::vector<std::shared_ptr<Bomb>> getBombList();
        void displayPlayer();
        void updateAnimationPlayer();
        bool getDeath();
        void update();
        void draw();
        std::vector<std::array<int, 5>> initControls();
        void setPosition(IS::pos coords);
        void setSpeed(float increase);
        void setNbBomb(int bomb);
        void setHuman(bool human);
        void setDeath(bool dead);
        void setBombRange(int range);
        void dropBomb();
        void dropBombIA();
        void updateIA();
        void setPrevPosition(IS::pos coords);

    private:
        unsigned int _animsCount = 0;
        ModelAnimation *_anims;
        int _animFrameCounter = 0;

        Sound _bonus;
        Model _model;
        Texture2D _texture;
        IS::pos _coords;
        IS::pos _prevCoords;
        IS::pos _size;
        int _nb_bomb;
        int _bomb_range;
        float _speed;
        bool _human;
        bool _dead;
        int _id;
        std::vector<std::shared_ptr<Bomb>> _bombList;
        std::vector<std::array<int, 5>> _controls;
};
