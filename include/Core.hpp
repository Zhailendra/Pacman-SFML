/*
** EPITECH PROJECT, 2023
** Pacman_SFML
** File description:
** Core.hpp
*/

#pragma once

#include "Loader.hpp"
#include "Graphical.hpp"

namespace pacman {
    class Core {
        public:
            Core();
            ~Core();

            void startGraphical();
            void initCore(const std::string &libPath);

        protected:
            std::string _libPath;
        private:
            LoaderGraphicalPtr _loaderGraphical;
            IGraphicalPtr _graphical;
        };

} // pacman
