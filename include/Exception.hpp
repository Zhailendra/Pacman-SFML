/*
** EPITECH PROJECT, 2023
** Pacman_SFML
** File description:
** Exception.hpp
*/

#pragma once

#include "Includes.hpp"

namespace pacman {
    class Error : public std::exception {
        public:
            explicit Error(std::string msg) : _msg(std::move(msg))
            {};

            const char *what() const noexcept override
            {
                return (_msg.c_str());
            }

        protected:
            const std::string _msg;
    };
    class Exception {
        public:
            Exception() = default;
            ~Exception() = default;

            void checkArguments(int ac);
            std::string getLibPath() const;
            std::string getGamePath() const;

        protected:
        private:
            std::string _libPath;
            std::string _gamePath;
    };

} // pacman
