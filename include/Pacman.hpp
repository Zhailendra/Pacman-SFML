/*
** EPITECH PROJECT, 2023
** Pacman_SFML
** File description:
** Pacman.hpp
*/

#pragma once

#include "Includes.hpp"

namespace pacman {

    class Pacman : public IPacman {
        public:
            Pacman();
            ~Pacman() override;

            void initPacman(short x, short y) override;

        protected:
        private:

    };

} // pacman
