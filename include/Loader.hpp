/*
** EPITECH PROJECT, 2023
** Pacman_SFML
** File description:
** Loader.hpp
*/

#pragma once

#include "Includes.hpp"

namespace pacman {
    template <typename LibLoader>
    class Loader {
        public:
            explicit Loader(const std::string &path) : _handle(dlopen(path.c_str(), RTLD_LAZY))
            {
                if (!_handle)
                    throw Error(ERROR_LIB);
            }
            ~Loader()
            {
                if (_handle)
                    dlclose(_handle);
            }

            std::shared_ptr<LibLoader> loadGraphical()
            {
                std::shared_ptr<pacman::IGraphical> lib;
                auto entryPoint = dlsym(_handle, GRAPHICAL_CONSTRUCTOR);

                if (!entryPoint)
                    throw Error(ERROR_SYM);
                auto *(*graphical)() = (pacman::IGraphical * (*) ()) entryPoint;
                lib = std::shared_ptr<pacman::IGraphical>(graphical());
                if (!lib)
                    throw Error(ERROR_SYMBOL);
                return (lib);
            }

            std::shared_ptr<LibLoader> loadGame()
            {
                std::shared_ptr<pacman::IMap> lib;
                auto entryPoint = dlsym(_handle, GAME_CONSTRUCTOR);

                if (!entryPoint)
                    throw Error(ERROR_SYM);
                auto *(*game)() = (pacman::IMap * (*) ()) entryPoint;
                lib = std::shared_ptr<pacman::IMap>(game());
                if (!lib)
                    throw Error(ERROR_SYMBOL);
                return (lib);
            }

        protected:
            void *_handle;
        private:
    };

    typedef Loader<IGraphical> LoaderGraphical;
    typedef std::shared_ptr<LoaderGraphical> LoaderGraphicalPtr;
    typedef Loader<IMap> LoaderGame;
    typedef std::shared_ptr<LoaderGame> LoaderGamePtr;

} // pacman
