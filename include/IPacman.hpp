/*
** EPITECH PROJECT, 2023
** Pacman_SFML
** File description:
** IPacman.hpp
*/

#pragma once

#include "IMap.hpp"

/* Globals */

constexpr int PACMAN_ANIM_SPEED = 4;
constexpr int PACMAN_ANIM_FRAME = 6;
constexpr int PACMAN_DEATH_FRAME = 12;
constexpr int PACMAN_SPEED = 2;
constexpr int SLOW_TIMER = 521;

namespace pacman {

    class IPacman {
    public:
        virtual ~IPacman() = default;
        virtual void initPacman(double x, double y) = 0;
        virtual void displayPacman(sf::RenderWindow &window, bool isPlaying) = 0;
        virtual void movePacman(int gameLevel, std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> &_map) = 0;
        virtual bool checkIfWall(bool isPellets, bool isDoor, double x, double y, std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> &map) = 0;
        virtual void setNbPellets(int nbPellets) = 0;
        virtual int getNbPellets() const = 0;
        virtual bool getAnim() const = 0;

        virtual void setAnim(int speed) = 0;
        virtual void reStartGame() = 0;
    };

    struct pos {
        double x;
        double y;

        bool operator==(const pos &other) const {
            return x == other.x && y == other.y;
        }
    };

} // pacman
