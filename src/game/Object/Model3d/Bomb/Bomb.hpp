/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-samuel.shemtov
** File description:
** bomb.hpp
*/

#pragma once

#include "../Model3d.hpp"
#include <cmath>

namespace IS {
    class Bomb : public Model3d {
        public:
            Bomb(const Vector3 &position, const Vector3 &dimensions, const Vector3 &scale, const Vector3 &speed, const Vector3 &rotation_axis, const float &rotation_angle,  const std::string &texture_path, const std::string &model_path, const std::string &model_animation_path);
            ~Bomb() = default;
            void displayExplosionBomb();
            void checkDropBomb(const Vector3 &coordsPlayer);
            float getRange();
            float getStartTime();
            int getTimeOutBomb();
            bool getBombUsed();
            void setBombRange(float range);

        private:
            int _animFrameCounter = 0;
            float _range;
            float _startTime;
            int _timeOutBomb;
            bool _time_is_up;
            bool _bomb_used;
    };
}