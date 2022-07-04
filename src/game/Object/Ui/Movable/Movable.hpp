/*
** EPITECH PROJECT, 2022
** Movable.hpp
** File description:
** Movable
*/

#ifndef MOVABLE_HPP_
#define MOVABLE_HPP_

#include "../Ui.hpp"

namespace IS {
    class Movable : public Ui {
        public:
            Movable(const Vector3 &position, const Vector3 &dimensions, const Vector3 &scale, const Color &color, const Vector3 &speed, const std::string &path, const bool &reset, const Vector3 &end_pos);
            ~Movable() = default;
            bool getReset();
            void setReset(const bool &reset);
            Vector3 getInitPos();
            void setInitPos(const Vector3 &init_pos);
            Vector3 getEndPos();
            void setEndPos(const Vector3 &end_pos);
        protected:
            bool _reset;
            Vector3 _init_pos;
            Vector3 _end_pos;
        private:
    };
}

#endif /* !MOVABLE_HPP_ */
