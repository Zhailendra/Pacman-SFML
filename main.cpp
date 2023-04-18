/*
** EPITECH PROJECT, 2023
** Pacman-SFML
** File description:
** main.cpp
*/

#include "Core.hpp"

int main(int ac, char **av)
{
    std::shared_ptr<pacman::Exception> exception(new pacman::Exception());
    std::shared_ptr<pacman::Core> core(new pacman::Core());
    try {
        exception->checkArguments(ac, av);
        core->initCore(exception->getLibPath(), exception->getGamePath());
        core->startGraphical();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
    return (0);
}
