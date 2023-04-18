/*
** EPITECH PROJECT, 2023
** Pacman_SFML
** File description:
** Graphical.hpp
*/

#pragma once

#include "Includes.hpp"
#include <SFML/Graphics.hpp>

namespace pacman {
    class Graphical {
        public:
            Graphical();
            ~Graphical();

            void runWindow();

        protected:
        private:
            sf::RenderWindow window;
            sf::VideoMode videoMode;
            sf::Event event;

    };

} // pacman
