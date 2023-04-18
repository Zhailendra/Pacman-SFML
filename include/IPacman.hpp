/*
** EPITECH PROJECT, 2023
** Pacman_SFML
** File description:
** IPacman.hpp
*/

#pragma once

#define PACMAN_CONSTRUCTOR "pacman_constructor"

namespace pacman {

    class IPacman {
        public:
            virtual ~IPacman() = default;
            virtual void runGame() = 0;
    };

} // pacman