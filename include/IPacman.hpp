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
constexpr unsigned char PACMAN_ANIM_FRAME = 6;
constexpr unsigned char PACMAN_DEATH_FRAME = 12;
constexpr unsigned char PACMAN_SPEED = 2;
constexpr unsigned short SLOW_TIMER = 521;

namespace pacman {

    class IPacman {
    public:
        virtual ~IPacman() = default;
        virtual void initPacman(short x, short y) = 0;
        virtual void displayPacman(sf::RenderWindow &window, bool isPlaying) = 0;
        virtual void movePacman(unsigned char gameLevel, std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> &_map) = 0;
        virtual bool checkIfWall(bool isPellets, bool isDoor, short x, short y, std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> &map) = 0;
        virtual void setNbPellets(int nbPellets) = 0;
        virtual int getNbPellets() const = 0;
        virtual bool getAnim() const = 0;

        virtual void setAnim(unsigned short speed) = 0;
        virtual void reStartGame() = 0;
    };

    struct pos {
        short x;
        short y;

        bool operator==(const pos &other) const {
            return x == other.x && y == other.y;
        }
    };

} // pacman
