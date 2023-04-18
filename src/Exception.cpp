/*
** EPITECH PROJECT, 2023
** Pacman_SFML
** File description:
** Exception.cpp
*/

#include "Exception.hpp"

namespace pacman {

    Exception::Exception()
    {
        std::cout << "Exception constructor" << std::endl;
    }

    Exception::~Exception()
    {
        std::cout << "Exception destructor" << std::endl;
    }

    void Exception::checkArguments(int ac, char **av)
    {
        if (ac != 2)
            throw Error( INVALID_ARG USAGE);
        _path = av[1];
        if (_path.find(".so") == std::string::npos)
            throw Error( INVALID_LIB USAGE);
    }

    std::string Exception::getPath() const
    {
        return _path;
    }
}
