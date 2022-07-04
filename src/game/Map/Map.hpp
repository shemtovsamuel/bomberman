/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-samuel.shemtov
** File description:
** map.hpp
*/

#pragma once

#include "../include/global/Global.hpp"
#include "../Object/Model3d/Player/Player.hpp"
#include "../Graphics/Graphics.hpp"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "raylib.h"
#include <random>
#include <ctime>
#include <cstdlib>
#include <array>
#include <vector>
#include <iostream>
#include <unordered_map>

class Map {
    public:
        Map();
        Map(int size, int max_players);
        ~Map();
        std::vector<std::string> getGrid();
        std::vector<IS::pos> getPlayersPos();
        std::vector<IS::pos> getBoxesPos();
        std::vector<IS::pos> getBonusPos();
        std::vector<IS::pos> getBlocksPos();
        int getNbBlocks();
        int getNbBoxes();
        int getNbBonus();
        void printGrid();
        int getRandom(int bound);
        int *get_direction(int direction, int *check_dir);
        void add_walls();
        void add_boxs();
        void get_player_positions();
        bool check_positions(int i, int j);
        void get_nb_boxes();
        void get_nb_blocks();
        void get_nb_bonus();
        void players_position();
        void blocks_position();
        void boxes_position();
        void bonus_position();
        void displayMap();
        void initKeys();
        std::vector<Player> checkCollisionBlocks(std::vector<Player> players);
        std::vector<Player> checkCollisionBonus(std::vector<Player> players);
        void checkCollisionBomb(std::vector<Player> players);
        std::vector<Player> checkCollisionPlayerBomb(std::vector<Player> players);
        int check_player_position(std::vector<std::vector<int>> players_pos, std::vector<int> player_pos);
        void set_player_positions(int nb_players);
        std::vector<std::string> generationIteration(int direction, int *check_dir, int *controller, int loop);

    private:
        int _size;
        int _max_players;
        int _nb_player_pos;
        int _nb_blocks;
        int _nb_boxes;
        int _nb_bonus;
        bool _draw;
        Image _wallImage;
        Image _boxImage;
        Image _floorImage;
        Image _bonusBombImage;
        Image _bonusMSImage;
        Texture2D _wallTexture;
        Texture2D _boxTexture;
        Texture2D _floorTexture;
        Texture2D _bonusBombTexture;
        Texture2D _bonusMSTexture;
        std::vector<std::vector<int>> _all_player_pos;
        std::vector<IS::pos> _players_pos;
        std::vector<IS::pos> _bonus_pos;
        std::vector<IS::pos> _blocks_pos;
        std::vector<IS::pos> _boxes_pos;
        std::vector<std::string> _grid;
};
