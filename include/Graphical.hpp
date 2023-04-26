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

            void setMap(IMapPtr map) override;

        protected:
            IMapPtr _map;
            unsigned char _gameLevel;
        private:
            sf::RenderWindow _window;
            sf::VideoMode _videoMode;
            sf::Event _event{};
            sf::Texture _textureMap;
            sf::Sprite _spriteMap;

    };

} // pacman
