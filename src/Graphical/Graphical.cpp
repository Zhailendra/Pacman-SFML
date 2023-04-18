/*
** EPITECH PROJECT, 2023
** Pacman_SFML
** File description:
** Graphical.cpp
*/

#include "Graphical.hpp"

namespace pacman {

    Graphical::Graphical()
    {
        videoMode.width = WINDOW_WIDTH;
        videoMode.height = WINDOW_HEIGHT;
        videoMode.bitsPerPixel = 32;
        window.create(videoMode, "Pacman", sf::Style::Close | sf::Style::Titlebar);
        window.setFramerateLimit(60);
    }

    void Graphical::runWindow()
    {
        while (window.isOpen()) {
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear(sf::Color::Black);
            window.display();
        }
    }

    extern "C" IGraphical *graphical_constructor()
    {
        return new Graphical();
    }

}