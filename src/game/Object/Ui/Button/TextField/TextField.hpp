/*
** EPITECH PROJECT, 2022
** TextField.hpp
** File description:
** TextField
*/

#ifndef TEXTFIELD_HPP_
#define TEXTFIELD_HPP_

#include "../Button.hpp"
#include "../../Movable/Text/Text.hpp"

namespace IS {
    class TextField : public Button {
        public:
            TextField(const Vector3 &position, const Vector3 &dimensions, const Vector3 &scale, const std::string &texture_path, const std::string &sound_path, const Vector3 offset, const Color &color, const std::string &font_path, const float &font_size, const float &spacing, const unsigned int &limit);
            ~TextField() = default;
            const Text &getText();
            void setText(std::unique_ptr<Text> text);
            unsigned int getLimit();
            void setLimit(unsigned int limit);
            void appendMarker();
            void replaceLast(char c);
            void popMarker();

        protected:
            std::unique_ptr<Text> _text;
            unsigned int _limit;
        private:
    };
}

#endif /* !TEXTFIELD_HPP_ */
