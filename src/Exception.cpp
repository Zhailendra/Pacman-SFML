/*
** EPITECH PROJECT, 2023
** Pacman_SFML
** File description:
** Exception.cpp
*/

#include "Exception.hpp"

namespace pacman {

    void Exception::checkArguments(int ac)
    {
        if (ac != 1)
            throw Error( INVALID_ARG USAGE);
        _libPath = "./libs/LibSFML.so";
        _gamePath = "./libs/Pacman.so";
        if (_libPath.find(".so") == std::string::npos ||
        _gamePath.find(".so") == std::string::npos)
            throw Error( INVALID_LIB USAGE);
    }

    std::string Exception::getLibPath() const
    {
        return _libPath;
    }

    std::string Exception::getGamePath() const
    {
        return _gamePath;
    }

}
