/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-samuel.shemtov
** File description:
** window
*/

#ifndef BOMBERMAN_WINDOW_H
#define BOMBERMAN_WINDOW_H

#include <string>
#include "raylib.h"

namespace IS {
    class Window {
    public:
        Window(int width, int height, const std::string &name, int fps = 60);
        ~Window();
        bool isOpen();
        void setSize(int width, int height);
    private:
        int _width;
        int _height;
        std::string _name;
        int _fps;
    };
}

#endif //BOMBERMAN_WINDOW_H
