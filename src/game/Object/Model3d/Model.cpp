
#include "Model.hpp"
#include "rlgl.h"

//************ ANIMATED *******************\\

IS::AnimatedModel::AnimatedModel(const xForm_t &transform, animatedModelConf_t model) : AModel(transform, model.model_file, model.texture_file) {
    unsigned int animsCount = 0;
    this->animation = LoadModelAnimations(model.animation_file.c_str(), &animsCount);
}

void IS::AnimatedModel::playAnimation(bool onlyFst) {
    int &animFrameCounter = this->animFrameCounter;
    animFrameCounter++;
    UpdateModelAnimation(this->model, this->animation[0], onlyFst ? 0 : animFrameCounter);
    if (animFrameCounter >= this->animation[0].frameCount)
        animFrameCounter = 0;
}

void IS::AnimatedModel::draw() {
    DrawModelEx(this->model,
                {this->transform.position.x, this->transform.position.y, this->transform.position.z},
                {this->transform.rotation.x, this->transform.rotation.y, this->transform.rotation.z},
                this->transform.rotationAngle,
                {this->transform.scale.x, this->transform.scale.y, this->transform.scale.z},
                WHITE);
}

void IS::AnimatedModel::draw(const xForm_t &transformation) {
    DrawModelEx(this->model,
                {transformation.position.x, transformation.position.y, transformation.position.z},
                {transformation.rotation.x, transformation.rotation.y, transformation.rotation.z},
                transformation.rotationAngle,
                {transformation.scale.x, transformation.scale.y, transformation.scale.z},
                WHITE);
}

ModelAnimation &IS::AnimatedModel::getAnimation() {
    return *this->animation;
}
//************ NON-ANIMATED *******************\\

IS::NonAnimatedModel::NonAnimatedModel(const xForm_t &transform, const std::string &fileName, const std::string &textureName) : AModel(transform, fileName, textureName) {}

void IS::NonAnimatedModel::draw() {
    DrawModel(this->model,
              { this->transform.position.x, this->transform.position.z, this->transform.position.y },
              this->transform.scale.x,
              WHITE);
}

void IS::NonAnimatedModel::drawEx(const xForm_t &transformation) {
    DrawModelEx(this->model,
                {transformation.position.x, transformation.position.y, transformation.position.z},
                {transformation.rotation.x, transformation.rotation.y, transformation.rotation.z},
                transformation.rotationAngle,
                {transformation.scale.x, transformation.scale.y, transformation.scale.z},
                WHITE);
}

void IS::NonAnimatedModel::draw(const xForm_t &transformation) {
    DrawModel(this->model,
              {transformation.position.x, transformation.position.z, transformation.position.y},
              transformation.scale.x,
              WHITE);
}