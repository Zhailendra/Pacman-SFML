/*
** EPITECH PROJECT, 2023
** Pacman_SFML
** File description:
** Type.hpp
*/

#pragma once

#include <iostream>
#include <memory>

namespace pacman {

    class IGraphical;
    class IPacman;
    class IMap;

    typedef std::shared_ptr<IGraphical> IGraphicalPtr;
    typedef std::shared_ptr<IMap> IMapPtr;
    typedef std::shared_ptr<IPacman> IPacmanPtr;
}