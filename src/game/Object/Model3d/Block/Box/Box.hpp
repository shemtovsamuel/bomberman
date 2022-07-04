/*
** EPITECH PROJECT, 2022
** Box.hpp
** File description:
** Box
*/

#ifndef BOX_HPP_
#define BOX_HPP_

#include "../Block.hpp"

namespace IS {
    class Box : public Block {
        public:
            Box(const Vector3 &position, const Vector3 &dimensions, const std::string &path);
            ~Box() = default;

        protected:
        private:
    };
}

#endif /* !BOX_HPP_ */
