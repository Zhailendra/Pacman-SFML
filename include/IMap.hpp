/*
** EPITECH PROJECT, 2023
** Pacman_SFML
** File description:
** IMap.hpp
*/

#pragma once

#include "Type.hpp"

/* Defines */

#define GAME_CONSTRUCTOR "game_constructor"

/* Globals */

constexpr unsigned char MAP_HEIGHT = 21;
constexpr unsigned char MAP_WIDTH = 21;

/* Enum */

enum Cell {
    WALL,
    DOOR,
    PELLET,
    ENERGIZER,
    EMPTY
};

namespace pacman {
    class IMap {
        public:
            virtual ~IMap() = default;
            virtual void initMap() = 0;
            virtual void initPacman() = 0;
            virtual void drawMap(sf::Sprite sprite, sf::RenderWindow &window) = 0;
            virtual IPacmanPtr getPacman() = 0;
            virtual std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> &getMap() = 0;
    };
} // pacman