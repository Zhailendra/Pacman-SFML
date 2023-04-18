/*
** EPITECH PROJECT, 2023
** Pacman_SFML
** File description:
** IGprahical.hpp
*/

#pragma once

#include "Type.hpp"
#include <SFML/Graphics.hpp>

#define GRAPHICAL_CONSTRUCTOR "graphical_constructor"

/* Globals */

constexpr unsigned char WINDOW_RESIZE = 2;

constexpr unsigned char OBJECT_SIZE = 16;

constexpr unsigned char FONT_SIZE = 16;

namespace pacman {

    class IGraphical {
        public:
            virtual ~IGraphical() = default;
            virtual void runWindow() = 0;
            virtual void manageEvents() = 0;
            virtual void setMap(IMapPtr map) = 0;
    };

} // pacman
