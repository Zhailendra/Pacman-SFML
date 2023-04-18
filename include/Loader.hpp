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

        protected:
            void *_handle;
        private:
    };

    typedef Loader<IGraphical> LoaderGraphical;
    typedef std::shared_ptr<LoaderGraphical> LoaderGraphicalPtr;

} // pacman
