/*
** EPITECH PROJECT, 2022
** Model3d.hpp
** File description:
** Model3d
*/

#pragma once

#include "../AObject.hpp"

namespace IS {
    class Model3d : public AObject {
        public:
            Model3d(const Vector3 &position, const Vector3 &dimensions, const Vector3 &scale, const Vector3 &speed, const Vector3 &rotation_axis, const float &rotation_angle,  const std::string &texture_path, const std::string &model_path);
            ~Model3d() = default;

            const Vector3 &getRotationAxis();
            void setRotationAxis(const Vector3 &rotation_axis);
            float getRotationAngle();
            void setRotationAngle(const float &rotation_angle);
            std::string getTexturePath();
            void setTexturePath(const std::string &texture_path);
            std::string getModelPath();
            void setModelPath(const std::string &model_path);

        protected:
            Vector3 _rotation_axis;
            float _rotation_angle;
            std::string _texture_path;
            std::string _model_path;
        private:
    };
}
