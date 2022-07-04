/*
** EPITECH PROJECT, 2022
** Sprite.hpp
** File description:
** Sprite
*/

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include "../Movable.hpp"

namespace IS {
    class Sprite : public Movable {
        public:
            Sprite(const Vector3 &position, const Vector3 &dimensions, const Vector3 &scale, const Vector3 &speed, const std::string &texture_path, const bool &reset, const Vector3 &end_pos);
            ~Sprite() = default;

        protected:
        private:
    };
}

#endif /* !SPRITE_HPP_ */
