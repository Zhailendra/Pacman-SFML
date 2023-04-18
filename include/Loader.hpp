/*
** EPITECH PROJECT, 2023
** Pacman_SFML
** File description:
** Loader.hpp
*/

#pragma once

#include "Includes.hpp"

namespace pacman {
    class Loader {
        public:
            Loader();
            ~Loader();

            void loadException(int ac, char **av);
            void loadLib();
            void loadGraphical();

        protected:
            void *_handle;
        private:
            std::shared_ptr<Exception> _exception;
    };

} // pacman
