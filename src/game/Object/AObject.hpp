/*
** EPITECH PROJECT, 2022
** AObject.hpp
** File description:
** AObject
*/

#pragma once

#include "Global.hpp"
#include "IObject.hpp"

namespace IS {
    class AObject : public IObject {
        public:
            AObject(const Vector3 &position, const Vector3 &dimensions, const Vector3 &scale, const Color &color, const Vector3 &speed);
            ~AObject() = default;
            bool getIsCategory(const objectCategory_e &category);
            void setIsCategory(const bool &value, const objectCategory_e &category);
            Vector3 getPosition();
            void setPosition(const Vector3 &position);
            Vector3 getDimensions();
            void setDimensions(const Vector3 &dimensions);
            Vector3 getScale();
            void setScale(const Vector3 &scale);
            Color getColor();
            void setColor(const Color &color);
            Vector3 getSpeed();
            void setSpeed(const Vector3 &speed);
        protected:
            bool _is[NB_CATEGORY];
            Vector3 _position;
            Vector3 _dimensions;
            Vector3 _scale;
            Color _color;
            Vector3 _speed;
        private:
    };
}
