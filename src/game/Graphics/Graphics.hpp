/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-samuel.shemtov
** File description:
** Graphics
*/

#ifndef Graphics_H
#define Graphics_H

#include <iostream>
#include <unordered_map>
#include <fstream>
#include "../Type/Type.hpp"
#include "../Error/Error.hpp"
#include "../Object/Ui/Button/TextField/TextField.hpp"
#include "../Object/Ui/Movable/Sprite/Sprite.hpp"
#include "../Object/Ui/Movable/Text/Text.hpp"
#include "../Object/Ui/Toggle/Toggle.hpp"

namespace IS {
    struct pos
    {
        float X;
        float Y;
        float Z;
    };

    class Graphics {
        private:
            Vector2 _window_size;
            std::string _name;
            int _fps;
            Camera _cam;
            std::unordered_map<std::string, Font> _fonts;
            std::unordered_map<std::string, Image> _images; //Contient une image en fonction d'un nom
            std::unordered_map<std::string, Texture2D> _textures2D; //Contient une texture 2D en fonction d'un nom
            std::unordered_map<std::string, Model> _models;
            std::unordered_map<std::string, std::pair<ModelAnimation *, unsigned int>> _model_animations;

        public:
            Graphics();
            ~Graphics();

            bool isWindowOpened();
            Vector2 getWindowSize();
            void setWindowSize(const Vector2 &window_size);
            int getFPS();
            float getFrameTime();
            double getTime();
            void setCursorState(bool state);

            void loadFont(const std::string &path);
            void loadImage(const std::string &path);
            void loadTexture(const std::string &path);
            void loadTextureFromImage(const std::string &path);
            void loadModel(const std::string &path);
            void loadModelAnimation(const std::string &path);
            void setMaterialTexture(const std::string &model, const std::string &texture);

            void beginDrawing();
            void endDrawing();
            void clearBackground();
            void beginMode3d();
            void endMode3d();

            void drawModel3d(std::shared_ptr<AObject> obj);
            void drawUi(std::shared_ptr<AObject> obj);
            // void drawCubeTexture(std::string texture_path, Vector3 position, Vector3 dimensions, Color color);
            void drawTexturePro(const std::string &path, const Rectangle &texture_rec, const Rectangle &dest,const Vector2 &origin, const float &rotation, const Color &color);
            void drawTextEx(const std::string &path, const std::string &text, const Vector2 &position, const float &font_size, const float &spacing, const Color &color);
            void drawTextureEx(const std::string &path, const Vector2 &position, const float &rotation, const float &scale, const Color &color);

            /**************************
             *         Core           *
             * ***********************/
            void createCamera(Vector3 position, Vector3 target, Vector3 up);
            void updateCamera();
            void drawCube(Vector3 position, Vector3 dimensions, Color);
            void drawPlane(Vector3 position, Vector2 size, Color);
    };
}

#endif