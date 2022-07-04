
#ifndef BOMBERMAN_MODEL_HPP
#define BOMBERMAN_MODEL_HPP

#include "AModel.hpp"

namespace IS {
    class AnimatedModel : public IS::AModel {
    public:
        AnimatedModel(const xForm_t &transform, animatedModelConf_t model);
        ~AnimatedModel() = default;
    public:
        void draw() override;
        void draw(const xForm_t &transformation) override;
        void drawEx(const xForm_t &transformation) override {}
        void playAnimation(bool onlyFst = false);
        ModelAnimation &getAnimation();
    private:
        ModelAnimation *animation = nullptr;
        int animFrameCounter = 0;
    };
    class NonAnimatedModel : public IS::AModel {
    public:
        NonAnimatedModel(const xForm_t &transform, const std::string &fileName,
                         const std::string &textureName = "");
        ~NonAnimatedModel() = default;
    public:
        void draw() override;
        void draw(const xForm_t &transformation) override;
        void drawEx(const xForm_t &transformation) override;
    };
}
#endif //BOMBERMAN_MODEL_H
