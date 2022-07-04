/*
** EPITECH PROJECT, 2022
** MyMap.hpp
** File description:
** MyMap
*/

#ifndef MYMAP_HPP_
#define MYMAP_HPP_

#include <iostream>
#include <vector>
#include <random>
#include "../Object/Model3d/Block/Bonus/Bonus.hpp"
#include "../Object/Model3d/Block/Box/Box.hpp"
#include "../Object/Model3d/Block/Ground/Ground.hpp"
#include "../Object/Model3d/Block/Wall/Wall.hpp"

namespace IS {
    class Map {
        public:
            Map(const int &size);
            ~Map() = default;
            void generationIteration();
            int getSize();
            std::vector<Vector3> getPlayerPos();
            std::vector<std::vector<std::shared_ptr<AObject>>> getBlocks();
            void replaceBlock(const int x, const int z, std::shared_ptr<AObject> block);

        protected:
            int _size;
            int _max_players;
            std::vector<Vector3> _player_pos;
            std::vector<std::vector<std::shared_ptr<AObject>>> _blocks;
        private:
            std::vector<Vector3> _free_pos;
            std::vector<std::string> _grid;
            std::pair<int, int >get_direction(int direction, std::pair<int, int> check_dir);
            void add_blocks();
            void compute_free_pos();
            bool check_positions(int z, int x);
            void set_player_positions();
            void fillBlocks();
    };
}

#endif /* !MYMAP_HPP_ */
