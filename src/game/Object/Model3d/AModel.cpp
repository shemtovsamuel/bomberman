
#include "AModel.hpp"

IS::AModel::AModel(const xForm_t &transform, const std::string &modelFilePath, const std::string &texturePath) {
    this->transform = transform;
    this->model = LoadModel(modelFilePath.c_str());
    if (texturePath != "") {
        this->texture = LoadTexture(texturePath.c_str());
        SetMaterialTexture(&this->model.materials[0], MATERIAL_MAP_DIFFUSE, this->texture);
    }
}

void IS::AModel::setPosition(const pos_t &position) {
    this->transform.position = position;
}

void IS::AModel::setRotation(const pos_t &rotation) {
    this->transform.rotation = rotation;
}

void IS::AModel::setScale(const pos_t &scale) {
    this->transform.scale = scale;
}

void IS::AModel::setAngle(const float &angle) {
    this->transform.rotationAngle = angle;
}

const pos_t &IS::AModel::getPosition() const {
    return this->transform.position;
}

const pos_t &IS::AModel::getRotation() const {
    return this->transform.rotation;
}

const pos_t &IS::AModel::getScale() const {
    return this->transform.scale;
}

Model &IS::AModel::getModel() {
    return this->model;
}

Texture2D &IS::AModel::getTexture() {
    return this->texture;
}
