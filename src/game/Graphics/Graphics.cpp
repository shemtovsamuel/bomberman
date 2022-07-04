/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-samuel.shemtov
** File description:
** Graphics
*/


#include "Graphics.hpp"

namespace IS {
    Graphics::Graphics() :
        _window_size(1920, 1080),
        _name("Bomberman"),
        _fps(120),
        _fonts({}),
        _images({}),
        _textures2D({}),
        _models({}),
        _model_animations({})
    {
        InitWindow(_window_size.x, _window_size.y, _name.c_str());
        SetTargetFPS(_fps);
    }

    Graphics::~Graphics()
    {
        for (auto &it : _model_animations)
            UnloadModelAnimations(it.second.first, it.second.second);
        _model_animations.clear();
        for (auto &it : _models)
            UnloadModel(it.second);
        _models.clear();
        for (auto &it : _textures2D)
            UnloadTexture(it.second);
        _textures2D.clear();
        for (auto &it : _images)
            UnloadImage(it.second);
        _images.clear();
        for (auto &it : _fonts)
            UnloadFont(it.second);
        _fonts.clear();
        if (IsWindowReady())
            CloseWindow();
    }

    bool Graphics::isWindowOpened()
    {
        return !WindowShouldClose();
    }

    Vector2 Graphics::getWindowSize()
    {
        return _window_size;
    }

    void Graphics::setWindowSize(const Vector2 &window_size)
    {
        _window_size = window_size;
        SetWindowSize(static_cast<int>(_window_size.x), static_cast<int>(_window_size.y));
    }

    int Graphics::getFPS()
    {
        return (GetFPS());
    }

    float Graphics::getFrameTime()
    {
        return (GetFrameTime());
    }

    double Graphics::getTime()
    {
        return (GetTime());
    }

    void Graphics::setCursorState(bool state)
    {
        if (state)
            ShowCursor();
        else
            HideCursor();
    }

    void Graphics::loadFont(const std::string &path)
    {
        if (_fonts.find(path) != _fonts.end())
            throw Error("font: '" + path + "' already exists", "Graphics::loadFont");
        std::ifstream file(path.c_str());
        if (!file.is_open())
            throw Error("file: '" + path + "' not found", "Graphics::loadFont");
        _fonts.insert({path, LoadFont(path.c_str())});
    }

    void Graphics::loadImage(const std::string &path)
    {
        if (_images.find(path) != _images.end())
            throw Error("image: '" + path + "' already exists", "Graphics::loadImage");
        std::ifstream file(path.c_str());
        if (!file.is_open())
            throw Error("file: '" + path + "' not found", "Graphics::loadImage");
        _images.insert({path, LoadImage(path.c_str())});
    }

    void Graphics::loadTexture(const std::string &path)
    {
        if (_textures2D.find(path) != _textures2D.end())
            throw Error("texture: '" + path + "' already exists", "Graphics::loadTexture");
        std::ifstream file(path.c_str());
        if (!file.is_open())
            throw Error("file: '" + path + "' not found", "Graphics::loadTexture");
        _textures2D.insert({path, LoadTexture(path.c_str())});
    }

    void Graphics::loadTextureFromImage(const std::string &path)
    {
        if (_textures2D.find(path) != _textures2D.end())
            throw Error("texture: '" + path + "' already exists", "Graphics::loadTextureFromImage");
        if (_images.find(path) == _images.end()) {
            try {
                loadImage(path);
            } catch (const Error &e) {
                std::cerr << e.where() << e.what() << std::endl;
            }
        }
        _textures2D.insert({path, LoadTextureFromImage(_images[path])});
        UnloadImage(_images[path]);
        _images.erase(path);
    }

    void Graphics::loadModel(const std::string &path)
    {
        if (_models.find(path) != _models.end())
            throw Error("model: '" + path + "' already exists", "Graphics::loadModel");
        std::ifstream file(path.c_str());
        if (!file.is_open())
            throw Error("file: '" + path + "' not found", "Graphics::loadModel");
        _models.insert({path, LoadModel(path.c_str())});
    }

    void Graphics::loadModelAnimation(const std::string &path)
    {
        if (_model_animations.find(path) != _model_animations.end())
            throw Error("model animation: '" + path + "' already exists", "Graphics::loadModelAnimation");
        std::ifstream file(path.c_str());
        if (!file.is_open())
            throw Error("file: '" + path + "' not found", "Graphics::loadModelAnimation");
        unsigned int animsCount = 0;
        _model_animations.insert({path, {LoadModelAnimations(path.c_str(), &animsCount), animsCount}});
    }

    void Graphics::setMaterialTexture(const std::string &model, const std::string &texture)
    {
        if (_models.find(model) == _models.end())
            throw Error("model: '" + model + "' doesn't exist", "Graphics::setMaterialTexture");
        if (_textures2D.find(texture) == _textures2D.end())
            throw Error("texture: '" + texture + "' doesn't exist", "Graphics::setMaterialTexture");
        SetMaterialTexture(&_models[model].materials[0], MATERIAL_MAP_DIFFUSE, _textures2D[texture]);
    }

    void Graphics::beginDrawing()
    {
        BeginDrawing();
    }

    void Graphics::endDrawing()
    {
        EndDrawing();
    }

    void Graphics::clearBackground()
    {
        ClearBackground(RAYWHITE);
    }

    void Graphics::beginMode3d()
    {
        BeginMode3D(_cam);
    }

    void Graphics::endMode3d()
    {
        EndMode3D();
    }

    void Graphics::drawModel3d(std::shared_ptr<AObject> obj)
    {
        // if (obj->getIsCategory())
    }

    void Graphics::drawUi(std::shared_ptr<AObject> obj)
    {
        if (obj->getIsCategory(BUTTON)) {
            auto button = std::dynamic_pointer_cast<Button>(obj);
            try {
                drawTexturePro(button->getTexturePath(), button->getTextureRec(), Rectangle(button->getPosition().x, button->getPosition().y, button->getDimensions().x * button->getScale().x, button->getDimensions().y * button->getScale().y), Vector2(), 0, button->getColor());
            } catch (const Error &e) {
                std::cerr << e.where() << e.what() << std::endl;
            }
            if (obj->getIsCategory(TEXT_FIELD)) {
                auto text_field = std::dynamic_pointer_cast<TextField>(button);
                auto text = text_field->getText();
                try {
                    drawTextEx(text.getTexturePath(), text.getContent(), Vector2(text.getPosition().x, text.getPosition().y), text.getFontSize(), text.getSpacing(), text.getColor());
                } catch (const Error &e) {
                    std::cerr << e.where() << e.what() << std::endl;
                }
            }
        }
        else if (obj->getIsCategory(MOVABLE)) {
            if (obj->getIsCategory(SPRITE)) {
                auto sprite = std::dynamic_pointer_cast<Sprite>(obj);
                try {
                    drawTextureEx(sprite->getTexturePath(), Vector2(sprite->getPosition().x, sprite->getPosition().y), 0, sprite->getScale().x, sprite->getColor());
                } catch (const Error &e) {
                    std::cerr << e.where() << e.what() << std::endl;
                }
            }
            else if (obj->getIsCategory(TEXT)) {
                auto text = std::dynamic_pointer_cast<Text>(obj);
                try {
                    drawTextEx(text->getTexturePath(), text->getContent(), Vector2(text->getPosition().x, text->getPosition().y), text->getFontSize(), text->getSpacing(), text->getColor());
                } catch (const Error &e) {
                    std::cerr << e.where() << e.what() << std::endl;
                }
            }
        }
        else if (obj->getIsCategory(TOGGLE)) {
            auto toggle = std::dynamic_pointer_cast<Toggle>(obj);
            try {
                drawTexturePro(toggle->getTexturePath(), toggle->getTextureRec(), Rectangle(toggle->getPosition().x, toggle->getPosition().y, toggle->getDimensions().x * toggle->getScale().x, toggle->getDimensions().y * toggle->getScale().y), Vector2(), 0, toggle->getColor());
            } catch (const Error &e) {
                std::cerr << e.where() << e.what() << std::endl;
            }
        }
    }

    void Graphics::drawTexturePro(const std::string &path, const Rectangle &texture_rec, const Rectangle &dest, const Vector2 &origin, const float &rotation, const Color &color)
    {
        if (_textures2D.find(path) == _textures2D.end())
            loadTextureFromImage(path);
        DrawTexturePro(_textures2D[path], texture_rec, dest, origin, rotation, color);
    }

    void Graphics::drawTextEx(const std::string &path, const std::string &text, const Vector2 &position, const float &font_size, const float &spacing, const Color &color)
    {
        if (_fonts.find(path) == _fonts.end()) {
            try {
                loadFont(path);
            } catch (const Error &e) {
                std::cerr << e.where() << e.what() << std::endl;
            }
        }
        DrawTextEx(_fonts[path], text.c_str(), position, font_size, spacing, color);
    }

    void Graphics::drawTextureEx(const std::string &path, const Vector2 &position, const float &rotation, const float &scale, const Color &color)
    {
        if (_textures2D.find(path) == _textures2D.end())
            loadTextureFromImage(path);
        DrawTextureEx(_textures2D[path], position, rotation, scale, color);
    }

    /**********************
     *       CAMERA       *
     * *******************/

    void Graphics::createCamera(Vector3 position, Vector3 target, Vector3 up)
    {
        _cam.position = position;
        _cam.target = target;
        _cam.up = up;
        _cam.fovy = 60.0f;
        _cam.projection = CAMERA_PERSPECTIVE;
        // SetCameraMode(_cam, CAMERA_THIRD_PERSON);
        SetCameraMode(_cam, CAMERA_FREE);
    }

    void Graphics::updateCamera()
    {
        UpdateCamera(&_cam);
    }

    void Graphics::drawCube(Vector3 position, Vector3 dimensions, Color color)
    {
        DrawCube(position, dimensions.x, dimensions.y, dimensions.z, color);
    }

    void Graphics::drawPlane(Vector3 position, Vector2 size, Color color)
    {
        // BeginDrawing();
        // ClearBackground(BLACK);
        // BeginMode3D(this->cam);
        // UpdateCamera(&this->cam);
    }

    // void Graphics::stop3Dscene()
    // {
        // EndMode3D();
        // EndDrawing();
        // DrawPlane(position, size, color);
    // }
}
