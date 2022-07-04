/*
** EPITECH PROJECT, 2022
** Ui.hpp
** File description:
** Ui
*/

#ifndef UI_HPP_
#define UI_HPP_

#include "../AObject.hpp"

namespace IS {
    enum state_e {
        NORMAL = 0,
        HOVER,
        CLICKED
    };

    class Ui : public AObject {
        public:
            Ui(const Vector3 &position, const Vector3 &dimensions, const Vector3 &scale, const Color &color, const Vector3 &speed, const std::string &path);
            ~Ui() = default;
            std::string getTexturePath();
            void setTexturePath(const std::string &path);

        protected:
            std::string _texture_path;
        private:
    };
}

#endif /* !UI_HPP_ */
