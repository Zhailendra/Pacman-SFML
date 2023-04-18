/*
** EPITECH PROJECT, 2023
** Pacman_SFML
** File description:
** Map.hpp
*/

#pragma once

#include "Includes.hpp"
#include "Pacman.hpp"

namespace pacman {

    class Map : public IMap {
        public:
            Map();
            ~Map() override = default;

            void initMap() override;
            void initPacman() override;
            void drawMap(sf::Sprite sprite, sf::RenderWindow &window) override;
            void setAllWalls();

            std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> setMap();

        protected:
            std::array<std::string, MAP_HEIGHT> _originalMap;
            std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> _map{};
            std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> _newMap{};

            IPacmanPtr _pacman;
        private:
            bool _isWallUp{};
            bool _isWallDown{};
            bool _isWallRight{};
            bool _isWallLeft{};

    };

} // pacman
