/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-samuel.shemtov
** File description:
** bomb.hpp
*/

#pragma once

#include <iostream>
#include "raylib.h"
#include "raymath.h"
#include <memory>
#include <vector>
#include <array>
#include "../../../../Graphics/Graphics.hpp"

class Bomb {
    public:
        Bomb(float range, int dropKey);
        void displayExplosionBomb();
        void checkDropBomb(IS::pos coordsPlayer);
        void checkDropBombIA(IS::pos coordsPlayer);
        void drawBomb();
        float getRange();
        float getStartTime();
        int getTimeOutBomb();
        IS::pos getCoords();
        ~Bomb();
        bool getBombUsed();
        void setBombRange(float range);

    private:
        ModelAnimation *_anims;
        Model _model;
        Texture2D _texture;
        unsigned int _animsCount = 0;
        int _animFrameCounter = 0;

        Image _explosionImage;
        Texture2D _explosionTexture;
        IS::pos _coords;
        float _range;
        int _dropKey;
        Sound _bomb_drop;
        Sound _bomb_explose;
        Sound _error;
        float _startTime;
        int _timeOutBomb;
        bool _time_is_up;
        bool _bomb_used;
        IS::pos _explosionSize;
};