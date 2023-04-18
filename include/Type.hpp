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

    typedef std::shared_ptr<IGraphical> IGraphicalPtr;
}