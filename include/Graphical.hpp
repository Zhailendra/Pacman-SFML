/*
** EPITECH PROJECT, 2023
** Pacman_SFML
** File description:
** Graphical.hpp
*/

#pragma once

#include "Includes.hpp"
#include "Core.hpp"

namespace pacman {
    class Graphical : public IGraphical {
        public:
            Graphical();
            ~Graphical() override = default;

            void runWindow() override;
            void manageEvents() override;
            void manageGame() override;
            void manageDrawing() override;

            void displayText(const std::string &toDisplay, bool atCenter, double x, double y) override;

            void setMap(IMapPtr map) override;

        protected:
            IMapPtr _map;
            int _gameLevel;
            bool _isPlaying;
        private:
            sf::RenderWindow _window;
            sf::VideoMode _videoMode;
            sf::Event _event{};
            sf::Texture _textureMap;
            sf::Sprite _spriteMap;

            sf::Sprite _font;
            sf::Texture _fontTexture;


    };

} // pacman
