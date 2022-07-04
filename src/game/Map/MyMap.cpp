/*
** EPITECH PROJECT, 2022
** MyMap.cpp
** File description:
** MyMap
*/

#include "MyMap.hpp"
#include "../Type/Type.hpp"

namespace IS {
    Map::Map(const int &size) :
        _size(size)
    {
    }

    void Map::generationIteration()
    {
        srand(time(0));
        int direction = std::rand() % (3 + 1);
        int loop = (50 * _size) + std::rand() % (200 + 1);
        std::pair<int, int> check_dir = {0, 0};
        std::pair<int, int> controller = {_size / 2, _size / 2};

        for (int i = 0; i < _size; ++i) {
            std::string line;
            line.append(_size, VOID);
            _grid.insert(_grid.begin(), line);
        }
        for (int i = 0; i < loop; ++i) {
            _grid[controller.first][controller.first] = FLOOR;
            if (std::rand() % (1 + 1) == 1)
                direction = std::rand() % (3 + 1);
            check_dir = get_direction(direction, check_dir);
            controller.first += check_dir.first;
            controller.second += check_dir.second;
            if (controller.first < 2 || controller.first >= _size - 2)
                controller.first += -check_dir.first * 2;
            if (controller.second < 2 || controller.second >= _size - 2)
                controller.second += -check_dir.second * 2;
        }
        add_blocks();
        compute_free_pos();
        set_player_positions();
    }

    int Map::getSize()
    {
        return _size;
    }

    std::vector<Vector3> Map::getPlayerPos()
    {
        return _player_pos;
    }

    std::vector<std::vector<std::shared_ptr<AObject>>> Map::getBlocks()
    {
        return _blocks;
    }

    void Map::add_blocks()
    {
        for (int z = 0; z < _size; ++z) {
            for (int x = 0; x < _size; ++x) {
                if (_grid[z][x] == FLOOR && (_grid[z+1][x] == VOID))
                    _grid[z+1][x] = WALL;
                if (_grid[z][x] == FLOOR && (_grid[z-1][x] == VOID))
                    _grid[z-1][x] = WALL;
                if (_grid[z][x] == FLOOR && (_grid[z][x+1] == VOID))
                    _grid[z][x+1] = WALL;
                if (_grid[z][x] == FLOOR && (_grid[z][x-1] == VOID))
                    _grid[z][x-1] = WALL;
            }
        }
        srand(time(0));
        int box = std::rand() % 6;
        int bonus_bomb = std::rand() % 20;
        int bonus_ms = std::rand() % 20;
        for (int z = 0; z < _size; ++z) {
            for (int x = 0; x < _size; ++x) {
                if (_grid[z][x] == FLOOR && (box % 2 == 0))
                    _grid[z][x] = BOX;
                if (_grid[z][x] == FLOOR && (bonus_bomb == 1))
                    _grid[z][x] = BONUS_BOMB;
                if (_grid[z][x] == FLOOR && (bonus_ms == 1))
                    _grid[z][x] = BONUS_MS;
                box = std::rand() % 6;
                bonus_bomb = std::rand() % 20;
                bonus_ms = std::rand() % 20;
            }
        }
    }

    bool Map::check_positions(int z, int x)
    {
        if (_grid[z][x] == FLOOR && (_grid[z+1][x] == FLOOR && _grid[z-1][x] == FLOOR))
            return(true);
        if (_grid[z][x] == FLOOR && (_grid[z][x+1] == FLOOR && _grid[z][x-1] == FLOOR))
            return(true);
        if (_grid[z][x] == FLOOR && (_grid[z+1][x] == FLOOR && _grid[z][x-1] == FLOOR))
            return(true);
        if (_grid[z][x] == FLOOR && (_grid[z+1][x] == FLOOR && _grid[z][x+1] == FLOOR))
            return(true);
        if (_grid[z][x] == FLOOR && (_grid[z-1][x] == FLOOR && _grid[z][x-1] == FLOOR))
            return(true);
        if (_grid[z][x] == FLOOR && (_grid[z-1][x] == FLOOR && _grid[z][x+1] == FLOOR))
            return(true);
        return (false);
    }

    void Map::compute_free_pos()
    {
        for (int z = 0; z <_size; ++z) {
            for (int x = 0; x < _size; ++x) {
                if (_grid[z][x] == FLOOR && check_positions(z ,x) == true) {
                    std::vector<int> player_positions = {z, x};
                    _free_pos.push_back(Vector3(x, 0.4, z));
                }
            }
        }
    }

    void Map::set_player_positions()
    {
        std::srand(time(0));
        int index = rand() % _player_pos.size();
        std::vector<Vector3> players_pos;
    
        for (int i = 0; i < _max_players; ++i) {
            Vector3 player_pos = _free_pos[index];
            players_pos.push_back(player_pos);
            _grid[player_pos.z][player_pos.x] = PLAYER;
            index = rand() % _player_pos.size();
        }
    }

    void Map::fillBlocks()
    {
        for (int z = 0; z < _size; z++) {
            for (int x = 0; x < _size; x++) {
                if (_grid[z][x] == FLOOR)
                    _blocks.emplace_back(std::make_shared<Ground>(Vector3(x, 0.45, z), Vector3(1, 0.1, 1), "ressources/3D/floor.png"));
                else if (_grid[z][x] == ::WALL)
                    _blocks.emplace_back(std::make_shared<Wall>(Vector3(x, 1, z), Vector3(1, 1.5, 1), "ressources/3D/wall.png"));
                else if (_grid[z][x] == ::BOX)
                    _blocks.emplace_back(std::make_shared<Box>(Vector3(x, 1, z), Vector3(1, 1, 1), "ressources/3D/box.png"));
                else if (_grid[z][x] == BONUS_BOMB)
                    _blocks.emplace_back(std::make_shared<Bonus>(Vector3(x, 1, z), Vector3(1, 1, 1), "ressources/3D/bonus_bomb.png", BOMB_UP));
                else if (_grid[z][x] == BONUS_MS)
                    _blocks.emplace_back(std::make_shared<Bonus>(Vector3(x, 1, z), Vector3(1, 1, 1), "ressources/3D/bonus_ms.png", SKATE));
                else
                    _blocks.emplace_back(nullptr);
            }
        }
    }
}
