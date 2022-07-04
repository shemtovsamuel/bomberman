/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-samuel.shemtov
** File description:
** bomb.cpp
*/

#include "Bomb.hpp"

namespace IS {
    Bomb::Bomb(const Vector3 &position, const Vector3 &dimensions, const Vector3 &scale, const Vector3 &speed, const Vector3 &rotation_axis, const float &rotation_angle,  const std::string &texture_path, const std::string &model_path, const std::string &model_animation_path) :
        Model3d(position, dimensions, scale, speed, rotation_axis, rotation_angle, model_path, model_animation_path)
    {
        _animFrameCounter = 0;
        _range = 1;
        _startTime = 0;
        _timeOutBomb = 2;
        _bomb_used = false;
        _time_is_up = false;
    }

    float Bomb::getRange()
    {
        return _range;
    }

    float Bomb::getStartTime()
    {
        return _startTime;
    }

    int Bomb::getTimeOutBomb()
    {
        return _timeOutBomb;
    }

    void Bomb::checkDropBomb(const Vector3 &coordsPlayer)
    {
        setBombRange(_range);
        if (_bomb_used == false) {
            _position.x = round(coordsPlayer.x);
            _position.y = round(coordsPlayer.y);
            _position.z = round(coordsPlayer.z);
        }
        if (_bomb_used == false) {
            _bomb_used = true;
            _startTime = GetTime();
        } else if (_bomb_used == true) {
            return;
        }
    }

    void Bomb::setBombRange(float range)
    {
        _range = range;
    }

    bool Bomb::getBombUsed()
    {
        return _bomb_used;
    }
}
