/*
** EPITECH PROJECT, 2022
** IObject.hpp
** File description:
** IObject
*/

#pragma once

#include <string>
#include <vector>
#include <memory>
#include "../Type/Type.hpp"

namespace IS {
    enum shapeType_e {
        S_BASIC = 0,
        S_LINES,
        S_GRADIENT
    };

    enum modelType_e {
        M_BASIC = 0,
        M_WIRES
    };

    enum objectCategory_e {
        MODEL_3D = 0,
        BLOCK,
        BOX,
        BONUS,
        GROUND,
        WALL,
        PLAYER,
        IA,
        HUMAN,
        BOMB,
        UI,
        BUTTON,
        TEXT_FIELD,
        MOVABLE,
        SPRITE,
        TEXT,
        TOGGLE,
        NB_CATEGORY
    };

    class IObject {
        public:
            virtual ~IObject() = default;
            virtual bool getIsCategory(const objectCategory_e &category) = 0;
            virtual void setIsCategory(const bool &value, const objectCategory_e &category) = 0;
            virtual Vector3 getPosition() = 0;
            virtual void setPosition(const Vector3 &position) = 0;
            virtual Vector3 getDimensions() = 0;
            virtual void setDimensions(const Vector3 &dimensions) = 0;
            virtual Vector3 getScale() = 0;
            virtual void setScale(const Vector3 &scale) = 0;
            virtual Color getColor() = 0;
            virtual void setColor(const Color &color) = 0;
            virtual Vector3 getSpeed() = 0;
            virtual void setSpeed(const Vector3 &speed) = 0;
        protected:
        private:
    };
}
