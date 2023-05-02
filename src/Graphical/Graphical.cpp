/*
** EPITECH PROJECT, 2023
** Pacman_SFML
** File description:
** Graphical.cpp
*/

#include "Graphical.hpp"

#include <cmath>
#include <utility>

namespace pacman {

    Graphical::Graphical() : _gameLevel(1), _isPlaying(true)
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
            if (_isPlaying) {
                _map->getPacman()->movePacman(_gameLevel, _map->getMap());
                if (_map->getPacman()->getNbPellets() == 0) {
                    _gameLevel++;
                    _isPlaying = false;
                    _map->getPacman()->setAnim(0);
                }
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                _isPlaying = true;
                _map->initMap();
                _map->getPacman()->reStartGame();
            }
            _window.clear(sf::Color::Black);
            if (_isPlaying) {
                _map->drawMap(_spriteMap, _window);
                displayText("CURRENT LEVEL: " + std::to_string(_gameLevel), false, false, OBJECT_SIZE * MAP_HEIGHT);
            }
            _map->getPacman()->displayPacman(_window, _isPlaying);
            if (_map->getPacman()->getAnim()) {
                (!_isPlaying) ? displayText("You won!\n\nPress Enter to play again\nor\nEscape to quit.",true, 0, 0) : displayText("GAME OVER", true, 0, 0);
            }
            _window.display();
        }
    }

    void Graphical::displayText(const std::string &toDisplay, bool atCenter, double x, double y)
    {
        double x1 = x;
        double y1 = y;
        _fontTexture .loadFromFile(FONT_ASSETS);
        int sizeWidth = static_cast<unsigned short>(_fontTexture.getSize().x / 96);
        _font.setTexture(_fontTexture);

        if (atCenter) {
            x1 = std::round(0.5f * double((OBJECT_SIZE * MAP_WIDTH - sizeWidth * toDisplay.substr(0, toDisplay.find_first_of('\n')).size())));
            y1 = std::round(0.5f * double((OBJECT_SIZE * MAP_HEIGHT - FONT_SIZE * (1 + std::count(toDisplay.begin(), toDisplay.end(), '\n')))));
        }
        for (std::string::const_iterator i = toDisplay.begin(); i != toDisplay.end(); i++) {
            if (*i == '\n') {
                (atCenter) ? x1 = static_cast<short>(std::round(0.5f * double((OBJECT_SIZE * MAP_WIDTH - sizeWidth * toDisplay.substr(1 + i - toDisplay.begin(), toDisplay.find_first_of('\n', 1 + i - toDisplay.begin()) - (1 + i - toDisplay.begin())).size())))) : x1 = x;
                y1 += FONT_SIZE;
                continue;
            }
            _font.setPosition(float(x1), float(y1));
            _font.setTextureRect(sf::IntRect(sizeWidth * (*i - 32), 0, sizeWidth, FONT_SIZE));
            x1 += sizeWidth;
            _window.draw(_font);
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