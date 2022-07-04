/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-samuel.shemtov
** File description:
** Map.cpp
*/

#include "Map.hpp"

Map::Map()
{
}

Map::Map(int size, int max_players) : _size(size), _max_players(max_players)
{
    int direction = getRandom(3);
    int loop = (50 * _size) + std::rand() % (200 + 1);
    int checkDirections[2] = {0, 0};
    int mapController[2] = {_size / 2, _size / 2};

    for (int i = 0; i < _size; ++i) {
        std::string line;
        line.append(_size, VOID);
        _grid.insert(_grid.begin(), line);
    }
    _wallImage = LoadImage("ressources/3D/wall.png");
    _boxImage = LoadImage("ressources/3D/box.png");
    _floorImage = LoadImage("ressources/3D/floor.png");
    _bonusBombImage = LoadImage("ressources/3D/bonus_bomb.png");
    _bonusMSImage = LoadImage("ressources/3D/bonus_ms.png");
    for (int i = 0; i < 2; i++) {
        ImageRotateCCW(&_bonusBombImage);
        ImageRotateCCW(&_bonusMSImage);
    }
    _draw = false;
    _grid = generationIteration(direction, checkDirections, mapController, loop);
}

Map::~Map()
{

}

std::vector<std::string> Map::getGrid()
{
    return (this->_grid);
}

std::vector<IS::pos> Map::getPlayersPos()
{
    return (this->_players_pos);
}

std::vector<IS::pos> Map::getBoxesPos()
{
    return (this->_boxes_pos);
}

std::vector<IS::pos> Map::getBlocksPos()
{
    return (this->_blocks_pos);
}

std::vector<IS::pos> Map::getBonusPos()
{
    return (this->_bonus_pos);
}

int Map::getNbBlocks()
{
    return(this->_nb_blocks);
}

int Map::getNbBonus()
{
    return(this->_nb_bonus);
}

int Map::getNbBoxes()
{
    return(this->_nb_boxes);
}

void Map::printGrid(void)
{
    for (int i = 0; i < _size; ++i) {
        std::cout << _grid[i] << std::endl;
    }
}

int Map::getRandom(int bound)
{
    return (std::rand() % ( bound + 1 ));
}

int *Map::get_direction(int direction, int *check_dir)
{
    switch (direction) {
        case 0:
            check_dir[0] = 1;
            check_dir[1] = 0;
            break;
        case 1:
            check_dir[0] = 0;
            check_dir[1] = -1;
            break;
        case 2:
            check_dir[0] = -1;
            check_dir[1] = 0;
            break;
        case 3:
            check_dir[0] = 0;
            check_dir[1] = 1;
            break;
    }
    return (check_dir);
}

bool Map::check_positions(int i, int j)
{
    if (_grid[i][j] == FLOOR && (_grid[i+1][j] == FLOOR && _grid[i-1][j] == FLOOR))
        return(true);
    if (_grid[i][j] == FLOOR && (_grid[i][j+1] == FLOOR && _grid[i][j-1] == FLOOR))
        return(true);
    if (_grid[i][j] == FLOOR && (_grid[i+1][j] == FLOOR && _grid[i][j-1] == FLOOR))
        return(true);
    if (_grid[i][j] == FLOOR && (_grid[i+1][j] == FLOOR && _grid[i][j+1] == FLOOR))
        return(true);
    if (_grid[i][j] == FLOOR && (_grid[i-1][j] == FLOOR && _grid[i][j-1] == FLOOR))
        return(true);
    if (_grid[i][j] == FLOOR && (_grid[i-1][j] == FLOOR && _grid[i][j+1] == FLOOR))
        return(true);
    return (false);
}

void Map::get_player_positions()
{
    _nb_player_pos = 0;

    for (int i = 0; i <_size; ++i) {
        for (int j = 0; j < _size; ++j) {
            if (_grid[i][j] == FLOOR && check_positions(i ,j) == true) {
                std::vector<int> player_positions = {i, j};
                _all_player_pos.push_back(player_positions);
                _nb_player_pos += 1;
            }
        }
    }
}

int Map::check_player_position(std::vector<std::vector<int>> players_pos, std::vector<int> player_pos)
{
    for (int i = 0; i < players_pos.size(); ++i) {
        if (players_pos[i][0] == player_pos[0] && players_pos[i][1] == player_pos[1])
            return (0);
    }
    return (1);
}

void Map::set_player_positions(int nb_players)
{
    std::srand(time(0));
    int index = rand() % _nb_player_pos;
    std::vector<std::vector<int>> players_pos;

    for (int i = 0; i < nb_players; ++i) {
        std::vector<int> player_pos = _all_player_pos[index];
        players_pos.push_back(player_pos);
        if (check_player_position(players_pos, player_pos) == 0)
            _grid[player_pos[0]][player_pos[1]] = PLAYER;
        else {
            players_pos.pop_back();
            --i;
        }
        index = rand() % _nb_player_pos;
    }
}

void Map::get_nb_blocks()
{
    _nb_blocks = 0;

    for (int i = 0; i < _size; ++i) {
        for (int j = 0; j < _size; ++j) {
            if (_grid[i][j] == BOX || _grid[i][j] == WALL)
                _nb_blocks += 1;
        }
    }
}

void Map::get_nb_boxes()
{
    _nb_boxes = 0;

    for (int i = 0; i < _size; ++i) {
        for (int j = 0; j < _size; ++j) {
            if (_grid[i][j] == BOX)
                _nb_boxes += 1;
        }
    }
}

void Map::get_nb_bonus()
{
    _nb_bonus = 0;

    for (int i = 0; i < _size; ++i) {
        for (int j = 0; j < _size; ++j) {
            if (_grid[i][j] == BONUS_BOMB || _grid[i][j] == BONUS_MS)
                _nb_bonus += 1;
        }
    }
}

void Map::players_position()
{
    int k = 0;
    IS::pos player_pos = {0, 0, 0};

    for (int i = 0; i < _max_players; i++) {
        player_pos = {0, 0.4f, 0};
        _players_pos.push_back(player_pos);
    }

    for (int i = 0; i <_size; ++i) {
        for (int j = 0; j < _size; ++j) {
            if (_grid[i][j] == PLAYER) {
                _players_pos[k] = player_pos;
                k++;
            }
            player_pos.X += 1.0f;
        }
        player_pos.X = 0;
        player_pos.Z += 1.0f;
    }
}

void Map::blocks_position()
{
    int k = 0;
    IS::pos block_pos = {0, 0, 0};

    for (int i = 0; i < _nb_blocks; i++) {
        block_pos = {0, 0.4f, 0};
        _blocks_pos.push_back(block_pos);
    }

    for (int i = 0; i <_size; ++i) {
        for (int j = 0; j < _size; ++j) {
            if (_grid[i][j] == BOX || _grid[i][j] == WALL) {
                _blocks_pos[k] = block_pos;
                k++;
            }
            block_pos.X += 1.0f;
        }
        block_pos.X = 0;
        block_pos.Z += 1.0f;
    }
}

void Map::bonus_position()
{
    int k = 0;
    IS::pos bonus_pos = {0, 0, 0};

    for (int i = 0; i < _nb_bonus; i++) {
        bonus_pos = {0, 0.4f, 0};
        _bonus_pos.push_back(bonus_pos);
    }

    for (int i = 0; i <_size; ++i) {
        for (int j = 0; j < _size; ++j) {
            if (_grid[i][j] == BONUS_BOMB || _grid[i][j] == BONUS_MS) {
                _bonus_pos[k] = bonus_pos;
                k++;
            }
            bonus_pos.X += 1.0f;
        }
        bonus_pos.X = 0;
        bonus_pos.Z += 1.0f;
    }
}

void Map::boxes_position()
{
    int k = 0;
    IS::pos box_pos = {0, 0, 0};

    for (int i = 0; i < _nb_boxes; i++) {
        box_pos = {0, 0.4f, 0};
        _boxes_pos.push_back(box_pos);
    }

    for (int i = 0; i <_size; ++i) {
        for (int j = 0; j < _size; ++j) {
            if (_grid[i][j] == BOX) {
                _boxes_pos[k] = box_pos;
                k++;
            }
            box_pos.X += 1.0f;
        }
        box_pos.X = 0;
        box_pos.Z += 1.0f;
    }
}


void Map::add_walls()
{
    for (int i = 0; i <_size; ++i) {
        for (int j = 0; j < _size; ++j) {
            if (_grid[i][j] == FLOOR && (_grid[i+1][j] == VOID))
                _grid[i+1][j] = WALL;
            if (_grid[i][j] == FLOOR && (_grid[i-1][j] == VOID))
                _grid[i-1][j] = WALL;
            if (_grid[i][j] == FLOOR && (_grid[i][j+1] == VOID))
                _grid[i][j+1] = WALL;
            if (_grid[i][j] == FLOOR && (_grid[i][j-1] == VOID))
                _grid[i][j-1] = WALL;
        }
    }
}

void Map::add_boxs()
{
    std::srand(time(0));
    int box = rand() % 6;
    int bonus_bomb = rand() % 20;
    int bonus_ms = rand() % 20;
    for (int i = 0; i <_size; ++i) {
        for (int j = 0; j < _size; ++j) {
            if (_grid[i][j] == FLOOR && (box % 2 == 0))
                _grid[i][j] = BOX;
            if (_grid[i][j] == FLOOR && (bonus_bomb == 1))
                _grid[i][j] = BONUS_BOMB;
            if (_grid[i][j] == FLOOR && (bonus_ms == 1))
                _grid[i][j] = BONUS_MS;
            box = std::rand() % 6;
            bonus_bomb = rand() % 20;
            bonus_ms = rand() % 20;
        }
    }
}

std::vector<std::string> Map::generationIteration(int direction, int *check_dir, int *controller, int loop)
{
    for (int i = 0; i < loop; ++i) {
        _grid[controller[1]][controller[0]] = FLOOR;
        if (getRandom(1) == 1)
            direction = getRandom(3);
        check_dir = get_direction(direction, check_dir);
        controller[0] += check_dir[0];
        controller[1] += check_dir[1];
        if (controller[0] < 2 || controller[0] >= _size - 2)
            controller[0] += -check_dir[0] * 2;
        if (controller[1] < 2 || controller[1] >= _size - 2)
            controller[1] += -check_dir[1] * 2;
    }
    add_walls();
    add_boxs();
    get_nb_blocks();
    get_nb_boxes();
    get_nb_bonus();
    get_player_positions();
    set_player_positions(MAX_PLAYERS);
    boxes_position();
    blocks_position();
    bonus_position();
    players_position();
    return (_grid);
}

void Map::displayMap()
{
    if (_draw == false) {
        _wallTexture = LoadTextureFromImage(_wallImage);
        _boxTexture = LoadTextureFromImage(_boxImage);
        _floorTexture = LoadTextureFromImage(_floorImage);
        _bonusBombTexture = LoadTextureFromImage(_bonusBombImage);
        _bonusMSTexture = LoadTextureFromImage(_bonusMSImage);
        _draw = true;
    }
    Vector3 wallPos = { 0, 1, 0};
    Vector3 boxPos = { 0, 1, 0 };
    Vector3 groundPos = { 0, 0.45f, 0 };
    Vector3 wallSize = { 1.0f, 1.5f, 1.0f };
    Vector3 boxSize = { 1.0f, 1.0f, 1.0f };
    Vector3 groundSize = { 1.0f, 0.1f, 1.0f };

    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            if (_grid[i][j] == WALL)
                DrawCubeTexture(_wallTexture, wallPos, wallSize.x, wallSize.y, wallSize.z, WHITE);
            if (_grid[i][j] == BOX)
                DrawCubeTexture(_boxTexture, boxPos, boxSize.x, boxSize.y, boxSize.z, WHITE);
            if (_grid[i][j] == FLOOR)
                DrawCubeTexture(_floorTexture, groundPos, groundSize.x, groundSize.y, groundSize.z, WHITE);
            if (_grid[i][j] == PLAYER)
                DrawCubeTexture(_floorTexture, groundPos, groundSize.x, groundSize.y, groundSize.z, WHITE);
            if (_grid[i][j] == BONUS_BOMB)
                DrawCubeTexture(_bonusBombTexture, boxPos, boxSize.x, boxSize.y, boxSize.z, WHITE);
            if (_grid[i][j] == BONUS_MS)
                DrawCubeTexture(_bonusMSTexture, boxPos, boxSize.x, boxSize.y, boxSize.z, WHITE);
            wallPos.x += wallSize.x;
            groundPos.x += wallSize.x;
            boxPos.x += boxSize.x;
        }
        wallPos.x = 0;
        wallPos.z += wallSize.z;
        groundPos.x = 0;
        groundPos.z += wallSize.z;
        boxPos.x = 0;
        boxPos.z += boxSize.z;
    }
}

std::vector<Player> Map::checkCollisionBlocks(std::vector<Player> players)
{
    IS::pos boxSize = { 1.0f, 1.0f, 1.0f };
    std::vector<IS::pos> blocksPos = getBlocksPos();

    for (int j = 0; j < getNbBlocks(); j++) {
        for (int i = 0; i < MAX_PLAYERS; i++) {
            if (players[i].getDeath() == true)
                continue;
            BoundingBox player = {(Vector3){ players[i].getPosition().X - 0.3f,
                                        players[i].getPosition().Y - 0.3f,
                                        players[i].getPosition().Z - 0.3f },
                            (Vector3){ players[i].getPosition().X + 0.3f,
                                        players[i].getPosition().Y + 0.3f,
                                        players[i].getPosition().Z + 0.3f }};
            BoundingBox box = {(Vector3){ blocksPos[j].X - boxSize.X/2,
                                        blocksPos[j].Y - boxSize.Y/2,
                                        blocksPos[j].Z - boxSize.Z/2 },
                            (Vector3){ blocksPos[j].X + boxSize.X/2,
                                        blocksPos[j].Y + boxSize.Y/2,
                                        blocksPos[j].Z + boxSize.Z/2 }};
            if (player.min.x <= box.max.x && player.max.x >= box.min.x &&
                player.min.y <= box.max.y && player.max.y >= box.min.y &&
                player.min.z <= box.max.z && player.max.z >= box.min.z) {
                players[i].setPosition(players[i].getPrevPosition());
                break;
            }
        }
    }
    return (players);
}


std::vector<Player> Map::checkCollisionBonus(std::vector<Player> players)
{
    IS::pos bonusSize = { 1.0f, 1.0f, 1.0f };
    std::vector<IS::pos> bonusPos = getBonusPos();

    for (int j = 0; j < getNbBonus(); j++) {
        for (int i = 0; i < MAX_PLAYERS; i++) {
            if (players[i].getDeath() == true)
                continue;
            BoundingBox player = {(Vector3){ players[i].getPosition().X - 0.3f,
                                        players[i].getPosition().Y - 0.3f,
                                        players[i].getPosition().Z - 0.3f },
                            (Vector3){ players[i].getPosition().X + 0.3f,
                                        players[i].getPosition().Y + 0.3f,
                                        players[i].getPosition().Z + 0.3f }};
            BoundingBox bonus = {(Vector3){ bonusPos[j].X - bonusSize.X/2,
                                        bonusPos[j].Y - bonusSize.Y/2,
                                        bonusPos[j].Z - bonusSize.Z/2 },
                            (Vector3){ bonusPos[j].X + bonusSize.X/2,
                                        bonusPos[j].Y + bonusSize.Y/2,
                                        bonusPos[j].Z + bonusSize.Z/2 }};
            if (player.min.x <= bonus.max.x && player.max.x >= bonus.min.x &&
                player.min.y <= bonus.max.y && player.max.y >= bonus.min.y &&
                player.min.z <= bonus.max.z && player.max.z >= bonus.min.z) {
                if (_grid[bonusPos[j].Z][bonusPos[j].X] == BONUS_BOMB)
                    players[i].setBombRange(1);
                if (_grid[bonusPos[j].Z][bonusPos[j].X] == BONUS_MS)
                    players[i].setSpeed(0.01);
                _grid[bonusPos[j].Z][bonusPos[j].X] = FLOOR;
                break;
            }
        }
    }
    return (players);
}

void Map::checkCollisionBomb(std::vector<Player> players)
{
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (players[i].getDeath() == true)
            continue;
        for (auto bomb : players[i].getBombList()) {
            if (!bomb->getBombUsed() || GetTime() - bomb->getStartTime() < bomb->getTimeOutBomb())
                continue;
            for (float i = 1; i <= bomb->getRange(); i++) {
                IS::pos pos = bomb->getCoords();
                int x = pos.X + (1 * i) > _size - 1 ? _size - 1 : pos.X + (1 * i);
                int z = pos.Z;
                _grid[z][x] = _grid[z][x] == BOX ? FLOOR : _grid[z][x];
                x = pos.X - (1 * i) < 0 ? 0 : pos.X - (1 * i);
                z = pos.Z;
                _grid[z][x] = _grid[z][x] == BOX ? FLOOR : _grid[z][x];
                x = pos.X;
                z = pos.Z + (1 * i) >= _size ? _size - 1 : pos.Z + (1 * i);
                _grid[z][x] = _grid[z][x] == BOX ? FLOOR : _grid[z][x];
                x = pos.X;
                z = pos.Z - (1 * i) < 0 ? 0 : pos.Z - (1 * i);
                _grid[z][x] = _grid[z][x] == BOX ? FLOOR : _grid[z][x];
            }
            blocks_position();
        }
    }
}

std::vector<Player> Map::checkCollisionPlayerBomb(std::vector<Player> players)
{
    for (int i = 0; i < players.size(); i++) {
        if (players[i].getDeath() == true)
            continue;
        for (auto bomb : players[i].getBombList()) {
            if (!bomb->getBombUsed() || GetTime() - bomb->getStartTime() < bomb->getTimeOutBomb())
                continue;
            for (float i = 1; i <= bomb->getRange(); i++) {
                for (int k = 0; k < players.size(); k++) {
                    if (players[i].getDeath() == true)
                        continue;
                    IS::pos pos = bomb->getCoords();
                    int x = pos.X;
                    int z = pos.Z;
                    if (x == round(players[k].getPosition().Z) && z == round(players[k].getPosition().Z)) {
                        players[k].setDeath(true);
                        continue;
                    }
                    x = pos.X + (1 * i) > _size - 1 ? _size - 1 : pos.X + (1 * i);
                    z = pos.Z;
                    if (x == round(players[k].getPosition().X) && z == round(players[k].getPosition().Z)) {
                        players[k].setDeath(true);
                        continue;
                    }
                    x = pos.X - (1 * i) < 0 ? 0 : pos.X - (1 * i);
                    z = pos.Z;
                    if (x == round(players[k].getPosition().X) && z == round(players[k].getPosition().Z)) {
                        players[k].setDeath(true);
                        continue;
                    }
                    x = pos.X;
                    z = pos.Z + (1 * i) >= _size ? _size - 1 : pos.Z + (1 * i);
                    if (x == round(players[k].getPosition().X) && z == round(players[k].getPosition().Z)) {
                        players[k].setDeath(true);
                        continue;
                    }
                    x = pos.X;
                    z = pos.Z - (1 * i) < 0 ? 0 : pos.Z - (1 * i);
                    if (x == round(players[k].getPosition().X) && z == round(players[k].getPosition().Z)) {
                        players[k].setDeath(true);
                        continue;
                    }
                }
            }    
            blocks_position();
        }
    }
    return (players);
}

