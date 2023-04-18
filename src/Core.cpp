/*
** EPITECH PROJECT, 2023
** Pacman_SFML
** File description:
** Core.cpp
*/

#include "Core.hpp"

namespace pacman {

    Core::Core()
    {
        std::cout << "Core created" << std::endl;
    }

    Core::~Core()
    {
        std::cout << "Core destroyed" << std::endl;
    }

    void Core::startGraphical()
    {
        _graphical->runWindow();
    }

    void Core::initCore(const std::string &libPath)
    {
        _libPath = libPath;
        _loaderGraphical = std::make_shared<LoaderGraphical>(_libPath);
        _graphical = _loaderGraphical->loadGraphical();
    }

}
