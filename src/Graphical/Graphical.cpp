/*
** EPITECH PROJECT, 2023
** Pacman_SFML
** File description:
** Graphical.cpp
*/

#include "Graphical.hpp"

#include <utility>

namespace pacman {

    Graphical::Graphical() : _gameLevel(0)
    {
        _videoMode.width = OBJECT_SIZE * MAP_WIDTH * WINDOW_RESIZE;
        _videoMode.height = (FONT_SIZE + OBJECT_SIZE * MAP_HEIGHT) * WINDOW_RESIZE;
        _videoMode.bitsPerPixel = 32;
        _window.create(_videoMode, "Pacman", sf::Style::Close | sf::Style::Resize | sf::Style::Titlebar);
        _window.setFramerateLimit(60);
        _window.setView(sf::View(sf::FloatRect(0, 0, OBJECT_SIZE * MAP_WIDTH, FONT_SIZE + OBJECT_SIZE * MAP_HEIGHT)));
        _textureMap.loadFromFile(MAP_ASSETS);
        _spriteMap.setTexture(_textureMap);
    }

    void Graphical::runWindow()
    {
        _map->initPacman();
        _map->initMap();
        while (_window.isOpen()) {
            manageEvents();
            _window.clear(sf::Color::Black);
            _map->drawMap(_spriteMap, _window);
            _map->getPacman()->movePacman(_gameLevel, _map->getMap());
            _map->getPacman()->displayPacman(_window);
            _window.display();
        }
    }

    void Graphical::manageEvents()
    {
        while (_window.pollEvent(_event)) {
            switch (_event.type) {
                case sf::Event::Closed:
                    _window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (_event.key.code == sf::Keyboard::Escape)
                        _window.close();
                    break;
                default:
                    break;
            }
        }
    }

    void Graphical::setMap(IMapPtr map)
    {
        _map = std::move(map);
    }

    extern "C" IGraphical *graphical_constructor()
    {
        return new Graphical();
    }

}