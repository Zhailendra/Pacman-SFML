/*
** EPITECH PROJECT, 2023
** Pacman_SFML
** File description:
** Pacman.cpp
*/

#include "Pacman.hpp"

#include <cmath>

namespace pacman {

    Pacman::Pacman() : _animTime(0), _animFrame(0), _direction(0), _slowGhost(0), _nbPellets(0), _doAnim(false)
    {
        std::cout << "Pacman created" << std::endl;
    }

    Pacman::~Pacman()
    {
        std::cout << "Pacman destroyed" << std::endl;
    }

    void Pacman::initPacman(short x, short y)
    {
        _pos = {x, y};
    }

    void Pacman::setNbPellets(int nbPellets)
    {
        _nbPellets = nbPellets;
    }

    int Pacman::getNbPellets() const
    {
        return _nbPellets;
    }

    bool Pacman::getAnim() const
    {
        return _doAnim;
    }

    void Pacman::displayPacman(sf::RenderWindow &window, bool isPlaying)
    {
        _animFrame = static_cast<unsigned char>(std::floor(_animTime / static_cast<float>(PACMAN_ANIM_SPEED)));

        if (!isPlaying) {
            if (_animTime < PACMAN_DEATH_FRAME * PACMAN_ANIM_SPEED) {
                _animTime++;
                _texture.loadFromFile("./assets/PacmanDisappear.png");
                _sprite.setTexture(_texture);
                _sprite.setTextureRect(sf::IntRect(OBJECT_SIZE * _animFrame, 0, OBJECT_SIZE, OBJECT_SIZE));
                window.draw(_sprite);
            } else
                _doAnim = true;
        } else {
            _sprite.setPosition(_pos.x, _pos.y);
            _texture.loadFromFile("./assets/Pacman.png");
            _sprite.setTexture(_texture);
            _sprite.setTextureRect(sf::IntRect(OBJECT_SIZE * _animFrame,OBJECT_SIZE * _direction,OBJECT_SIZE, OBJECT_SIZE));
            window.draw(_sprite);
            _animTime = (1 + _animTime) % (PACMAN_ANIM_FRAME * PACMAN_ANIM_SPEED);
        }
    }

    void Pacman::setAnim(unsigned short speed)
    {
        _animTime = speed;
    }

    void Pacman::reStartGame()
    {
        _animTime = 0;
        _slowGhost = 0;
        _direction = 0;
        _doAnim = false;
    }

    bool Pacman::checkIfWall(bool isPellets, bool isDoor, short x, short y, std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> &map)
    {
        bool isWall = false;
        float x1 = x / static_cast<float>(OBJECT_SIZE);
        float y1 = y / static_cast<float>(OBJECT_SIZE);
        short x2 = 0;
        short y2 = 0;

        for (unsigned char i = 0; i < 4; i++) {
            x2 = 0;
            y2 = 0;
            switch (i) {
                case 0:
                    x2 = static_cast<short>(std::floor(x1));
                    y2 = static_cast<short>(std::floor(y1));
                    break;
                case 1:
                    x2 = static_cast<short>(std::ceil(x1));
                    y2 = static_cast<short>(std::floor(y1));
                    break;
                case 2:
                    x2 = static_cast<short>(std::floor(x1));
                    y2 = static_cast<short>(std::ceil(y1));
                    break;
                case 3:
                    x2 = static_cast<short>(std::ceil(x1));
                    y2 = static_cast<short>(std::ceil(y1));
                    break;
            }
            if (0 <= x2 && 0 <= y2 && MAP_HEIGHT > y2 && MAP_WIDTH > x2) {
                if (!isPellets) {
                    (Cell::WALL == map[x2][y2]) ? isWall = true :
                    (!isDoor && Cell::DOOR == map[x2][y2]) ? isWall = true : 0;
                } else {
                    (Cell::PELLET == map[x2][y2]) ? map[x2][y2] = Cell::EMPTY, _nbPellets-- :
                    (Cell::ENERGIZER == map[x2][y2]) ? isWall = true, map[x2][y2] = Cell::EMPTY : 0;
                }
            }
        }
        return isWall;
    }

    void Pacman::movePacman(unsigned char gameLevel, std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> &map)
    {
        _isWall[0] = checkIfWall(false, false, PACMAN_SPEED + _pos.x, _pos.y, map);
        _isWall[1] = checkIfWall(false, false, _pos.x, _pos.y - PACMAN_SPEED, map);
        _isWall[2] = checkIfWall(false, false, _pos.x - PACMAN_SPEED, _pos.y, map);
        _isWall[3] = checkIfWall(false, false, _pos.x, _pos.y + PACMAN_SPEED, map);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            !_isWall[1] ? _direction = 1 : 0;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            !_isWall[3] ? _direction = 3 : 0;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            !_isWall[2] ? _direction = 2 : 0;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            !_isWall[0] ? _direction = 0 : 0;
        }
        if (!_isWall[_direction]) {
            switch (_direction) {
                case 0:
                    _pos.x += PACMAN_SPEED;
                    break;
                case 1:
                    _pos.y -= PACMAN_SPEED;
                    break;
                case 2:
                    _pos.x -= PACMAN_SPEED;
                    break;
                case 3:
                    _pos.y += PACMAN_SPEED;
                    break;
            }
        }
        if (-OBJECT_SIZE >= _pos.x)
            _pos.x = OBJECT_SIZE * MAP_WIDTH - PACMAN_SPEED;
        else if (OBJECT_SIZE * MAP_WIDTH <= _pos.x)
            _pos.x = PACMAN_SPEED - OBJECT_SIZE;
        if (checkIfWall(true, false, _pos.x, _pos.y, map))
            _slowGhost = static_cast<unsigned short>(SLOW_TIMER / pow(2, gameLevel));
        else
            _slowGhost = std::max(0, _slowGhost - 1);
    }

}