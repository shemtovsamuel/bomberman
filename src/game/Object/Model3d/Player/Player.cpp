/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-samuel.shemtov
** File description:
** Player.cpp
*/


#include <memory>
#include "Player.hpp"
#include "Bomb/Bomb.hpp"
#include "../../../Scene/AScene.hpp"

Player::Player(int id, IS::pos coords, IS::pos size, int nb_bomb) : _id(id), _coords(coords), _size(size), _nb_bomb(nb_bomb)
{
    _bonus = LoadSound("ressources/audio/bonus.wav");
    _model = LoadModel("ressources/3D/PlayerModelWalk.iqm");
    std::string path = "ressources/3D/Player" + std::to_string(id) + ".png";
    _texture = LoadTexture(path.c_str());
    SetMaterialTexture(&_model.materials[0], MATERIAL_MAP_DIFFUSE, _texture);
    _nb_bomb = 1;
    _bomb_range = 1;
    _speed = 0.03;
    _animsCount = 0;
    _anims = LoadModelAnimations("ressources/3D/PlayerAnimWalk.iqm", &_animsCount);
    _animFrameCounter = 0;
    _human = false;
    _dead = false;

    _controls = initControls();
    for (int i = 0; i < _nb_bomb; i++)
        _bombList.push_back(std::make_shared<Bomb>(_bomb_range, _controls[_id][4]));
}

Player::~Player()
{
}

Model Player::getModel()
{
    return _model;
}

IS::pos Player::getPosition()
{
    return _coords;
}


IS::pos Player::getPrevPosition()
{
    return _prevCoords;
}

IS::pos Player::getSize()
{
    return _size;
}

int Player::getNbBomb()
{
    return _nb_bomb;
}

int Player::getBombRange()
{
    return _bomb_range;
}

float Player::getSpeed()
{
    return _speed;
}

std::vector<std::shared_ptr<Bomb>> Player::getBombList()
{
    return _bombList;
}

std::vector<std::array<int, 5>> Player::initControls()
{
    std::array<int, 5> keys1{265, 263, 264, 262, 32};
    std::array<int, 5> keys2{87, 65, 83, 68, 69};
    std::array<int, 5> keys3{89, 71, 72, 74, 85};
    std::array<int, 5> keys4{80, 76, 59, 39, 91};
    _controls.push_back(keys1);
    _controls.push_back(keys2);
    _controls.push_back(keys3);
    _controls.push_back(keys4);

    return _controls;
}

std::array<int, 5> Player::getControls()
{
    return _controls[_id];
}

void::Player::dropBomb()
{
    for (int i = 0; i < _nb_bomb; i++)
        _bombList[i]->checkDropBomb(_coords);
}

void::Player::dropBombIA()
{
    for (int i = 0; i < _nb_bomb; i++)
        _bombList[i]->checkDropBombIA(_coords);
}

bool Player::getDeath()
{
    return _dead;
}

void Player::setDeath(bool dead)
{
    _dead = dead;
}

void Player::displayPlayer()
{
    DrawModelEx(_model, (Vector3){_coords.X, _coords.Y, _coords.Z}, (Vector3){ 90.0f, 00.0f, 0.0f }, 90.0f, (Vector3){_size.X, _size.Y, _size.Z}, WHITE);
}

void Player::setSpeed(float increase)
{
    _speed += increase;
    PlaySound(_bonus);
}

void Player::setNbBomb(int bomb)
{
    _nb_bomb += bomb;
    PlaySound(_bonus);
}

void Player::setHuman(bool human)
{
    _human = human;
}

void Player::setBombRange(int range)
{
    _bomb_range += range;
    PlaySound(_bonus);
    for (int i = 0; i < _nb_bomb; i++)
        _bombList[i]->setBombRange(_bomb_range);
}

void Player::updateAnimationPlayer()
{
    UpdateModelAnimation(_model, _anims[0], _animFrameCounter);
    if (_animFrameCounter >= _anims[0].frameCount)
        _animFrameCounter = 0;
}

void Player::update()
{
    setPrevPosition(_coords);
    if (_human) {
        if (IsKeyDown(getControls()[0]) || IsKeyDown(getControls()[2]) ||
            IsKeyDown(getControls()[1]) || IsKeyDown(getControls()[3]))
            _animFrameCounter++;
        if (IsKeyDown(getControls()[0])) {
            _model.transform = MatrixRotateXYZ((Vector3){ 0, 0, 3});
            _coords.Z -= _speed;
        }
        if (IsKeyDown(getControls()[2])) {
            _model.transform = MatrixRotateXYZ((Vector3){ 0, 0, 0});
            _coords.Z += _speed;
        }
        if (IsKeyDown(getControls()[3])) {
            _model.transform = MatrixRotateXYZ((Vector3){ 0, 0, 1.80});
            _coords.X += _speed;
        }
        if (IsKeyDown(getControls()[1])) {
            _model.transform = MatrixRotateXYZ((Vector3){ 0, 0, -1.80});
            _coords.X -= _speed;
        }
        dropBomb();
    } else
        updateIA();
}

void Player::draw()
{
    displayPlayer();
    updateAnimationPlayer();
    for (int i = 0; i < _nb_bomb; i++)
        _bombList[i]->drawBomb();
}

void Player::setPosition(IS::pos coords)
{
    _coords = coords;
}

void Player::setPrevPosition(IS::pos coords)
{
    _prevCoords = coords;
}

void Player::updateIA()
{
    std::srand(time(0));
    int rand_x = rand() % 5;

    if (rand_x == 0) {
        _model.transform = MatrixRotateXYZ((Vector3){ 0, 0, 3});
        _coords.Z -= _speed;
    }
    if (rand_x == 1) {
        _model.transform = MatrixRotateXYZ((Vector3){ 0, 0, 0});
        _coords.Z += _speed;
    }
    if (rand_x == 2) {
        _model.transform = MatrixRotateXYZ((Vector3){ 0, 0, 1.80});
        _coords.X += _speed;
    }
    if (rand_x == 3) {
        _model.transform = MatrixRotateXYZ((Vector3){ 0, 0, -1.80});
        _coords.X -= _speed;
    }
    if (rand_x == 4) {
        dropBombIA();
        _coords = _prevCoords;
    }
}