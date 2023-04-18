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
            void initCore(const std::string &libPath, const std::string &gamePath);

        protected:
            std::string _libPath;
            std::string _gamePath;
        private:
            LoaderGraphicalPtr _loaderGraphical;
            LoaderGamePtr _loaderGame;
            IGraphicalPtr _graphical;
            IMapPtr _map;
        };

} // pacman
