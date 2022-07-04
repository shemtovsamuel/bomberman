/*
** EPITECH PROJECT, 2022
** Text.hpp
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include "../Movable.hpp"

namespace IS {
    class Text : public Movable {
        public:
            Text(const Vector3 &position, const Vector3 &scale, const Color &color, const Vector3 &speed, const std::string &font_path, const bool &reset, const Vector3 &end_pos, const std::string &content, const float &font_size, const float &spacing);
            ~Text() = default;
            std::string getContent();
            void setContent(const std::string &content);
            float getFontSize();
            void setFontSize(const float &font_size);
            float getSpacing();
            void setSpacing(const float &spacing);

        protected:
            std::string _content;
            float _font_size;
            float _spacing;
        private:
    };
}

#endif /* !TEXT_HPP_ */
