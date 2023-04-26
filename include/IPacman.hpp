/*
** EPITECH PROJECT, 2023
** Pacman_SFML
** File description:
** IPacman.hpp
*/

#pragma once

#include "IMap.hpp"

/* Globals */

constexpr unsigned char PACMAN_ANIM_SPEED = 4;
constexpr unsigned char PACMAN_SPEED = 2;
constexpr unsigned short SLOW_TIMER = 521;

namespace pacman {

    class IPacman {
    public:
        virtual ~IPacman() = default;
        virtual void initPacman(short x, short y) = 0;
        virtual void displayPacman(sf::RenderWindow &window) = 0;
        virtual void initWalls(std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> map) = 0;
        virtual bool checkIfWall(bool isPellets, bool isDoor, short x, short y) = 0;
        virtual void movePacman(unsigned char gameLevel) = 0;
    };

    struct pos {
        short x;
        short y;

        bool operator==(const pos &other) const {
            return x == other.x && y == other.y;
        }
    };

} // pacman
