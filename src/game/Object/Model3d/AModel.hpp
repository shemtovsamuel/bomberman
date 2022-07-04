
#ifndef BOMBERMAN_AMODEL_HPP
#define BOMBERMAN_AMODEL_HPP

#include "../../Graphics/Graphics.hpp"

typedef struct pos_s
{
    float x;
    float y;
    float z;
} pos_t;

typedef struct {
    std::string model_file;
    std::string animation_file;
    std::string texture_file;
} animatedModelConf_t;

typedef struct xForm_s {
    pos_t position = {0, 0, 0};
    pos_t rotation = {0.0, 1.0, 0.0};
    pos_t scale = {1, 1, 1};
    float rotationAngle = -90.0;
} xForm_t;

namespace IS {
    class AModel {
    public:
        AModel(const xForm_t &transform, const std::string &modelFilePath,
               const std::string &texturePath = "");
        ~AModel() = default;
    public:
        virtual void draw() = 0;
        virtual void draw(const xForm_t &transform) = 0;
        virtual void drawEx(const xForm_t &transform) = 0;
    public:
        void setPosition(const pos_t &);
        void setRotation(const pos_t &);
        void setScale(const pos_t &);
        void setAngle(const float &);
        const pos_t &getPosition() const;
        const pos_t &getRotation() const;
        const pos_t &getScale() const;
        Model &getModel();
        Texture2D &getTexture();
    protected:
        xForm_t transform = {0};
        Model model;
        Texture2D texture = {0};
    };
}


#endif //BOMBERMAN_AMODEL_HPP
