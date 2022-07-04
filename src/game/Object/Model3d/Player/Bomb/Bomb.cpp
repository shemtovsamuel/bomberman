/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-samuel.shemtov
** File description:
** bomb.cpp
*/

#include "Bomb.hpp"

Bomb::Bomb(float range, int dropKey) : _range(range)
{
    _bomb_drop = LoadSound("ressources/audio/bomb_drop.wav");
    _bomb_explose = LoadSound("ressources/audio/bomb_explode.wav");
    _error = LoadSound("ressources/audio/error.wav");
    _startTime = 0;
    _timeOutBomb = 2;
    _bomb_used = false;
    _time_is_up = false;
    _coords = {0};
    _explosionSize = { range, range, range};
    _model = LoadModel("ressources/3D/BombModel.iqm");
    _texture = LoadTexture("ressources/3D/BombTexture.png");
    SetMaterialTexture(&_model.materials[0], MATERIAL_MAP_DIFFUSE, _texture);

    _explosionImage = LoadImage("ressources/3D/boom.png");
    _dropKey = dropKey;
    _animsCount = 0;
    _anims = LoadModelAnimations("ressources/3D/BombAnim.iqm", &_animsCount);
    _animFrameCounter = 0;
}

Bomb::~Bomb()
{
    UnloadSound(_bomb_drop);
    UnloadSound(_bomb_explose);
    UnloadModel(_model);
    UnloadTexture(_texture);
    UnloadModelAnimations(_anims, _animsCount);
    UnloadSound(_error);
}

float Bomb::getRange()
{
    return _range;
}

IS::pos Bomb::getCoords()
{
    return _coords;
}

float Bomb::getStartTime()
{
    return _startTime;
}

int Bomb::getTimeOutBomb()
{
    return _timeOutBomb;
}

void Bomb::checkDropBomb(IS::pos coordsPlayer)
{
    setBombRange(_range);
    if (_bomb_used == false) {
        _coords.X = round(coordsPlayer.X);
        _coords.Y = round(coordsPlayer.Y);
        _coords.Z = round(coordsPlayer.Z);
    }
    if (IsKeyPressed(_dropKey) && _bomb_used == false) {
        PlaySound(_bomb_drop);
        _bomb_used = true;
        _startTime = GetTime();
    } else if (IsKeyPressed(_dropKey) && _bomb_used == true) {
        PlaySound(_error);
        return;
    }
}

void Bomb::checkDropBombIA(IS::pos coordsPlayer)
{
    setBombRange(_range);
    if (_bomb_used == false) {
        _coords.X = round(coordsPlayer.X);
        _coords.Y = round(coordsPlayer.Y);
        _coords.Z = round(coordsPlayer.Z);
    }
    if (_bomb_used == false) {
        _bomb_used = true;
        _startTime = GetTime();
    } else if (_bomb_used == true)
        return;
}

void::Bomb::drawBomb()
{
    if (!_bomb_used)
        return;
    UpdateModelAnimation(_model, _anims[0], _animFrameCounter);
    if (_animFrameCounter >= _anims[0].frameCount)
        _animFrameCounter = 0;

    _animFrameCounter++;
    DrawModelEx(_model, (Vector3){_coords.X, _coords.Y, _coords.Z}, (Vector3){ 90.0f, 00.0f, 0.0f }, 90.0f, (Vector3){ 1, 1, 1 }, WHITE);
    if (GetTime() - _startTime > _timeOutBomb)
        displayExplosionBomb();
}

void Bomb::displayExplosionBomb()
{
    _explosionTexture = LoadTextureFromImage(_explosionImage);
    PlaySound(_bomb_explose);
    DrawCubeTexture(_explosionTexture, {_coords.X, _coords.Y, _coords.Z}, 1.0f, 1.0f, 1.0f, WHITE);
    for (float i = 1; i <= _range; i++) {
        DrawCubeTexture(_explosionTexture, {_coords.X + (1 * i), _coords.Y, _coords.Z}, 1.0f, 1.0f, 1.0f, WHITE);
        DrawCubeTexture(_explosionTexture, {_coords.X - (1 * i), _coords.Y, _coords.Z}, 1.0f, 1.0f, 1.0f, WHITE);
        DrawCubeTexture(_explosionTexture, {_coords.X, _coords.Y, _coords.Z + (1 * i)}, 1.0f, 1.0f, 1.0f, WHITE);
        DrawCubeTexture(_explosionTexture, {_coords.X, _coords.Y, _coords.Z - (1 * i)}, 1.0f, 1.0f, 1.0f, WHITE);
    }
    if (GetTime() - _startTime > _timeOutBomb * 1.1)
        _bomb_used = false;
}

void Bomb::setBombRange(float range)
{
    _range = range;
}

bool::Bomb::getBombUsed()
{
    return _bomb_used;
}
