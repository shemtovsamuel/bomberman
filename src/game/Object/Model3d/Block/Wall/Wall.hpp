/*
** EPITECH PROJECT, 2022
** Wall.hpp
** File description:
** Wall
*/

#ifndef WALL_HPP_
#define WALL_HPP_

#include "../Block.hpp"

namespace IS {
    class Wall : public Block {
        public:
            Wall(const Vector3 &position, const Vector3 &dimensions, const std::string &path);
            ~Wall() = default;

        protected:
        private:
    };
}

#endif /* !WALL_HPP_ */
