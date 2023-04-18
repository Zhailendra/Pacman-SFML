/*
** EPITECH PROJECT, 2023
** Pacman-SFML
** File description:
** main.cpp
*/

#include "Loader.hpp"

int main(int ac, char **av)
{
    std::shared_ptr<pacman::Loader> loader(new pacman::Loader());
    try {
        loader->loadException(ac, av);
        loader->loadLib();
        loader->loadGraphical();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
    return (0);
}
