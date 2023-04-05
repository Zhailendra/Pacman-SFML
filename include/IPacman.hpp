/*
** EPITECH PROJECT, 2023
** Pacman-SFML
** File description:
** IPacman.hpp
*/

#pragma once

#include <iostream>

namespace Pacman {
    class IPacman {
    public:
        virtual ~IPacman() = default;

        virtual void run() = 0;
    };
}