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

            void initPacman(double x, double y) override;
            void displayPacman(sf::RenderWindow &window, bool isPlaying) override;
            void movePacman(int gameLevel, std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> &map) override;
            bool checkIfWall(bool isPellets, bool isDoor, double x, double y, std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> &map) override;

            void setNbPellets(int nbPellets) override;
            int getNbPellets() const override;
            bool getAnim() const override;

            void setAnim(int speed) override;
            void reStartGame() override;

        protected:
            int _animTime;
            int _animFrame;
            int _direction;
            int _slowGhost;
            bool _doAnim;
            int _nbPellets;
        private:
            std::array<bool, 4> _isWall{};
            pos _pos{};
            sf::Sprite _sprite;
            sf::Texture _texture;
    };

} // pacman
