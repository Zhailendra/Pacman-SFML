/*
** EPITECH PROJECT, 2023
** Pacman_SFML
** File description:
** Pacman.hpp
*/

#pragma once

#include "Includes.hpp"

namespace pacman {

    class Pacman : public IPacman {
        public:
            explicit Pacman();
            ~Pacman() override;

            void initPacman(short x, short y) override;
            void displayPacman(sf::RenderWindow &window) override;
            void movePacman(unsigned char gameLevel, std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> &map) override;
            bool checkIfWall(bool isPellets, bool isDoor, short x, short y, std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> &map) override;

            void setNbPellets(int nbPellets) override;
            int getNbPellets() const override;

        protected:
            unsigned short _animTime;
            unsigned char _animFrame;
            unsigned char _direction;
            unsigned short _slowGhost;
            int _nbPellets;
        private:
            std::array<bool, 4> _isWall{};
            pos _pos{};
            sf::Sprite _sprite;
            sf::Texture _texture;
    };

} // pacman
