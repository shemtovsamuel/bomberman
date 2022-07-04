/*
** EPITECH PROJECT, 2022
** Bonus.hpp
** File description:
** Bonus
*/

#ifndef BONUS_HPP_
#define BONUS_HPP_

#include "../Block.hpp"

namespace IS {
    enum bonus_e {
        BOMB_UP,
        SKATE
    };

    class Bonus : public Block {
        public:
            Bonus(const Vector3 &position, const Vector3 &dimensions, const std::string &path, const bonus_e &bonus);
            ~Bonus() = default;

        protected:
            bonus_e _bonus;
        private:
    };
}

#endif /* !BONUS_HPP_ */
