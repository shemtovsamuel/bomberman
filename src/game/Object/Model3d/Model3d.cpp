/*
** EPITECH PROJECT, 2022
** Model3d.cpp
** File description:
** Model3d
*/

#include "Model3d.hpp"

namespace IS {
    Model3d::Model3d(const Vector3 &position, const Vector3 &dimensions, const Vector3 &scale, const Vector3 &speed, const Vector3 &rotation_axis, const float &rotation_angle, const std::string &texture_path, const std::string &model_path) :
        AObject(position, dimensions, scale, Color::White(), speed),
        _rotation_axis(rotation_axis),
        _rotation_angle(rotation_angle),
        _texture_path(texture_path),
        _model_path(model_path)
    {
        setIsCategory(true, MODEL_3D);
    }

    const Vector3 &Model3d::getRotationAxis()
    {
        return _rotation_axis;
    }

    void Model3d::setRotationAxis(const Vector3 &rotation_axis)
    {
        _rotation_axis = rotation_axis;
    }

    float Model3d::getRotationAngle()
    {
        return _rotation_angle;
    }

    void Model3d::setRotationAngle(const float &rotation_angle)
    {
        _rotation_angle = rotation_angle;
    }

    std::string Model3d::getTexturePath()
    {
        return _texture_path;
    }

    void Model3d::setTexturePath(const std::string &texture_path)
    {
        _texture_path = texture_path;
    }

    std::string Model3d::getModelPath()
    {
        return _model_path;
    }

    void Model3d::setModelPath(const std::string &model_path)
    {
        _model_path = model_path;
    }
}
