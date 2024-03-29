/*
** EPITECH PROJECT, 2023
** Pacman_SFML
** File description:
** Map.cpp
*/

#include "Map.hpp"

namespace pacman {

    Map::Map() : _nbPellets(0)
    {
        _originalMap = {
                " ################### ",
                " #........#........# ",
                " #o##.###.#.###.##o# ",
                " #.................# ",
                " #.##.#.#####.#.##.# ",
                " #....#...#...#....# ",
                " ####.### # ###.#### ",
                "    #.#   0   #.#    ",
                "#####.# ##=## #.#####",
                "     .  #123#  .     ",
                "#####.# ##### #.#####",
                "    #.#       #.#    ",
                " ####.# ##### #.#### ",
                " #........#........# ",
                " #.##.###.#.###.##.# ",
                " #o.#.....P.....#.o# ",
                " ##.#.#.#####.#.#.## ",
                " #....#...#...#....# ",
                " #.######.#.######.# ",
                " #.................# ",
                " ################### "
        };
    }

    void Map::initMap()
    {
        _map = setMap();
    }

    void Map::initPacman()
    {
        _pacman = std::make_shared<Pacman>();
    }

    IPacmanPtr Map::getPacman()
    {
        return _pacman;
    }

    std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> &Map::getMap()
    {
        return _map;
    }

    std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> Map::setMap()
    {
        _nbPellets = 0;
        for (unsigned char i = 0; i < MAP_HEIGHT; i++) {
            for (unsigned char j = 0; j < MAP_WIDTH; j++) {
                _newMap[j][i] = Cell::EMPTY;
                switch (_originalMap[i][j]) {
                    case '#':
                        _newMap[j][i] = Cell::WALL;
                        break;
                    case '=':
                        _newMap[j][i] = Cell::DOOR;
                        break;
                    case '.':
                        _newMap[j][i] = Cell::PELLET;
                        _nbPellets++;
                        break;
                    case 'o':
                        _newMap[j][i] = Cell::ENERGIZER;
                        break;
                    case 'P':
                        _pacman->initPacman(OBJECT_SIZE * j, OBJECT_SIZE * i);
                        break;
                    case '0':
                        _ghostsPos[0].x = OBJECT_SIZE * j;
                        _ghostsPos[0].y = OBJECT_SIZE * i;
                        break;
                    case '1':
                        _ghostsPos[1].x = OBJECT_SIZE * j;
                        _ghostsPos[1].y = OBJECT_SIZE * i;
                        break;
                    case '2':
                        _ghostsPos[2].x = OBJECT_SIZE * j;
                        _ghostsPos[2].y = OBJECT_SIZE * i;
                        break;
                    case '3':
                        _ghostsPos[3].x = OBJECT_SIZE * j;
                        _ghostsPos[3].y = OBJECT_SIZE * i;
                        break;
                }
            }
        }
        _pacman->setNbPellets(_nbPellets);
        return _newMap;
    }

    void Map::drawMap(sf::Sprite sprite, sf::RenderWindow &window)
    {
        for (unsigned char i = 0; i < MAP_WIDTH; i++) {
            for (unsigned char j = 0; j < MAP_HEIGHT; j++) {
                sprite.setPosition(static_cast<float>(OBJECT_SIZE * i), static_cast<float>(OBJECT_SIZE * j));
                switch (_map[i][j]) {
                    case Cell::WALL:
                        setAllWalls();
                        (j < MAP_HEIGHT - 1) ? (Cell::WALL == _map[i][1 + j]) ? _isWallDown = true : 0 : 0;
                        (0 < i) ? (Cell::WALL == _map[i - 1][j]) ? _isWallLeft = true : 0 : _isWallLeft = true;
                        (i < MAP_WIDTH - 1) ? (Cell::WALL == _map[1 + i][j]) ? _isWallRight = true : 0 : _isWallRight = true;
                        (0 < j) ? (Cell::WALL == _map[i][j - 1]) ? _isWallUp = true : 0 : 0;
                        sprite.setTextureRect(sf::IntRect(OBJECT_SIZE * (_isWallDown + 2 * (_isWallLeft + 2 * (_isWallRight + 2 * _isWallUp))), 0, OBJECT_SIZE, OBJECT_SIZE));
                        window.draw(sprite);
                        break;
                    case Cell::DOOR:
                        sprite.setTextureRect(sf::IntRect(2 * OBJECT_SIZE, OBJECT_SIZE, OBJECT_SIZE, OBJECT_SIZE));
                        window.draw(sprite);
                        break;
                    case Cell::PELLET:
                        sprite.setTextureRect(sf::IntRect(0, OBJECT_SIZE, OBJECT_SIZE, OBJECT_SIZE));
                        window.draw(sprite);
                        break;
                    case Cell::ENERGIZER:
                        sprite.setTextureRect(sf::IntRect(OBJECT_SIZE, OBJECT_SIZE, OBJECT_SIZE, OBJECT_SIZE));
                        window.draw(sprite);
                        break;
                    case Cell::EMPTY:
                        break;
                }
            }
        }
    }

    void Map::setAllWalls()
    {
        _isWallUp = false;
        _isWallDown = false;
        _isWallRight = false;
        _isWallLeft = false;
    }

    extern "C" IMap *game_constructor()
    {
        return new Map();
    }
}
