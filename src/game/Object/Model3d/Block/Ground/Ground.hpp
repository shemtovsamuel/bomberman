/*
** EPITECH PROJECT, 2022
** Ground.hpp
** File description:
** Ground
*/

#ifndef GROUND_HPP_
#define GROUND_HPP_

#include "../Block.hpp"

namespace IS {
    class Ground : public Block {
        public:
            Ground(const Vector3 &position, const Vector3 &dimensions, const std::string &path);
            ~Ground() = default;

        protected:
        private:
    };
}

#endif /* !GROUND_HPP_ */
