/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-samuel.shemtov
** File description:
** window
*/

#include "window.hpp"

namespace IS {
    Window::Window(int width, int height, const std::string &name, int fps) :
        _width(width),
        _height(height),
        _name(name),
        _fps(fps)
    {
        InitWindow(_width, _height, _name.c_str());
        SetTargetFPS(_fps);
    }

    Window::~Window()
    {
        if (IsWindowReady())
            CloseWindow();
    }

    bool Window::isOpen()
    {
        return !WindowShouldClose();
    }

    void Window::setSize(int width, int height)
    {
        _width = width;
        _height = height;
        SetWindowSize(_width, _height);
    }
}