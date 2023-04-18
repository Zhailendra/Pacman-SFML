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
        _graphical->setMap(_map);
        _graphical->runWindow();
    }

    void Core::initCore(const std::string &libPath, const std::string &gamePath)
    {
        _libPath = libPath;
        _gamePath = gamePath;
        _loaderGraphical = std::make_shared<LoaderGraphical>(_libPath);
        _graphical = _loaderGraphical->loadGraphical();
        _loaderGame = std::make_shared<LoaderGame>(_gamePath);
        _map = _loaderGame->loadGame();
    }

}
