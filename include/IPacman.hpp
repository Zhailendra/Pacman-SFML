/*
** EPITECH PROJECT, 2023
** Pacman_SFML
** File description:
** IPacman.hpp
*/

#pragma once

namespace pacman {

    class IPacman {
    public:
        virtual ~IPacman() = default;
        virtual void initPacman(short x, short y) = 0;
    };

} // pacman
