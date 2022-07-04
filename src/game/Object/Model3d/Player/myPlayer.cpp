/*
** EPITECH PROJECT, 2022
** MyPlayer
** File description:
** myPlayer
*/

#include "myPlayer.hpp"

namespace IS {
    Player::Player(const Vector3 &position, const Vector3 &dimensions, const Vector3 &scale, const Vector3 &speed, const Vector3 &rotation_axis, const float &rotation_angle,  const std::string &texture_path, const std::string &model_path, const std::string &model_animation_path) :
        Model3d(position, dimensions, scale, speed, rotation_axis, rotation_angle, texture_path, model_path),
        _nb_bomb(1),
        _bomb_range(1),
        _model_animation_path(model_animation_path)
    {
        setIsCategory(true, PLAYER);
    }

    Vector3 Player::getPrevPosition()
    {
        return _prev_position;
    }

    int Player::getNbBomb()
    {
        return _nb_bomb;
    }

    int Player::getBombRange()
    {
        return _bomb_range;
    }

    void Player::setSpeed(float increase)
    {
        _speed += increase;
    }

    void Player::setNbBomb(int bomb)
    {
        _nb_bomb += bomb;
    }

    void Player::setBombRange(int range)
    {
        _bomb_range += range;
        for (int i = 0; i < _nb_bomb; i++)
            _bomb_list[i]->setBombRange(_bomb_range);
    }

            void dropBomb();

    void Player::setPrevPosition(const Vector3 &pos)
    {
        _prev_position = pos;
    }

    void Player::dropBomb()
    {
        for (int i = 0; i < _nb_bomb; i++)
            _bomb_list[i]->checkDropBomb(_position);
    }
}
