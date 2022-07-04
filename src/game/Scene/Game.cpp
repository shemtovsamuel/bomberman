/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-samuel.shemtov
** File description:
** game.cpp
*/

#include "Game.hpp"

Game::Game(IS::SceneManager &scene_manager, IS::Graphics &graphics, IS::Audio &audio, IS::Event &event) :
    AScene(scene_manager, graphics, audio, event)
{
    float size = _scene_manager.getMapSize();
    this->_map = Map(size, MAX_PLAYERS);
    this->_nb_alive = MAX_PLAYERS;
    this->_background = LoadTexture("assets/background.png");
    _graphics.createCamera(IS::Vector3(0, (size + size / 3), size / 3), IS::Vector3(0, -100, 2 ), IS::Vector3(0.0f, 1.0f, 0.0f));
}

Game::~Game()
{
}

void Game::onActivate()
{
}

void Game::onDeactivate()
{
}

void Game::processInput()
{
}

void Game::update()
{
    runGame();
}

// void Game::setCamera(Camera camera)
// {
//     this->_camera = camera;
// }

// Camera Game::getCamera()
// {
//     return this->_camera;
// }

void Game::setMap(Map map)
{
    this->_map = map;
}

Map Game::getMap()
{
    return this->_map;
}

void Game::setPlayer(Player player)
{
    this->_players.push_back(player);
}

std::vector<Player> Game::getPlayers()
{
    return this->_players;
}

int Game::getLastPlayerId()
{
    for (int i = 0; i < this->_players.size(); i++) {
        if (this->_players[i].getDeath() == false) {
            return i;
        }
    }
    return -1;
}

int Game::getNbAlive()
{
    return this->_nb_alive;
}

void Game::updateNbAlive()
{
    this->_nb_alive = MAX_PLAYERS;
    for (int i = 0; i < this->_players.size() and _nb_alive != 1; i++)
        if (this->_players[i].getDeath() == true)
            _nb_alive--;
}

bool Game::endGame()
{
    if (_nb_alive == 1)
        return true;
    return false;
}

void Game::setPlayers()
{
    Player player1(0, this->_map.getPlayersPos()[0], { 0.0033f, 0.0025f, 0.0033f }, 1);
    Player player2(1, this->_map.getPlayersPos()[1], { 0.0033f, 0.0025f, 0.0033f }, 1);
    Player player3(2, this->_map.getPlayersPos()[2], { 0.0033f, 0.0025f, 0.0033f }, 1);
    Player player4(3, this->_map.getPlayersPos()[3], { 0.0033f, 0.0025f, 0.0033f }, 1);
    _players.push_back(player1);
    _players.push_back(player2);
    _players.push_back(player3);
    _players.push_back(player4);
    for (int j = 0; j < NB_HUMANS; j++)
        _players[j].setHuman(true);
}

void Game::updateGame()
{
    if (endGame() == false) {
        updateNbAlive();
        // UpdateCamera(&_camera);
        for (int i = 0; i < MAX_PLAYERS; ++i)
            if (_players[i].getDeath() == false)
                _players[i].update();
        _players = _map.checkCollisionBlocks(_players);
        _players = _map.checkCollisionBonus(_players);
        _map.checkCollisionBomb(_players);
        _players = _map.checkCollisionPlayerBomb(_players);
    }
}

void Game::drawGame()
{
    _graphics.beginMode3d();
        DrawTexture(_background, _background.width, 0, WHITE);
        _map.displayMap();
        for (int i = 0; i < MAX_PLAYERS; ++i)
            if (_players[i].getDeath() == false)
                _players[i].draw();
    _graphics.endMode3d();
    DrawFPS(10, 10);
    if (endGame() == true) {
        int i = getLastPlayerId();
        DrawText("The game is over", _screenSize[0] / 2 - 405, _screenSize[1] / 2 - 105, 100, GRAY);
        DrawText("The game is over", _screenSize[0] / 2 - 400, _screenSize[1] / 2 - 100, 100, WHITE);
    }
}

void Game::runGame()
{  
    setPlayers();
    while (_graphics.isWindowOpened()) {
        _graphics.clearBackground();
        updateGame();
        _graphics.beginDrawing();
            drawGame();
        _graphics.endDrawing();
    }
    exit(0);
}