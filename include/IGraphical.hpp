/*
** EPITECH PROJECT, 2023
** Pacman_SFML
** File description:
** IGprahical.hpp
*/

#pragma once

#define GRAPHICAL_CONSTRUCTOR "graphical_constructor"

namespace pacman {

    class IGraphical {
        public:
            virtual ~IGraphical() = default;
            virtual void runWindow() = 0;
    };

} // pacman
