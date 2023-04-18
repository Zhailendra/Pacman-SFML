/*
** EPITECH PROJECT, 2023
** Pacman_SFML
** File description:
** Loader.cpp
*/

#include "Loader.hpp"

namespace pacman {

    Loader::Loader()
    {
        std::cout << "Loader constructor" << std::endl;
        _exception = std::make_shared<Exception>();
    }

    Loader::~Loader()
    {
        std::cout << "Loader destructor" << std::endl;
        if (_handle)
            dlclose(_handle);
    }

    void Loader::loadException(int ac, char **av)
    {
        _exception->checkArguments(ac, av);
    }

    void Loader::loadLib()
    {
        _handle = dlopen(_exception->getPath().c_str(), RTLD_LAZY);
        if (!_handle)
            throw Error( ERROR_LIB);
    }

    void Loader::loadGraphical()
    {

    }

}