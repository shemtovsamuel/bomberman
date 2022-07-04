/*
** EPITECH PROJECT, 2022
** Block.hpp
** File description:
** Block
*/

#ifndef BLOCK_HPP_
#define BLOCK_HPP_

#include "../Model3d.hpp"

namespace IS {
    class Block : public Model3d {
        public:
            Block(const Vector3 &position, const Vector3 &dimensions, const std::string &path);
            ~Block() = default;

        protected:
        private:
    };
}

#endif /* !BLOCK_HPP_ */
