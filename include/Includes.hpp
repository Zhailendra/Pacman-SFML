/*
** EPITECH PROJECT, 2023
** Pacman_SFML
** File description:
** Includes.hpp
*/

#pragma once

/* libraries */

#include <iostream>
#include <memory>
#include <utility>
#include <dlfcn.h>

/* Class */

#include "Exception.hpp"

/* Defines */

#define INVALID_ARG "Error: Invalid number of arguments"
#define INVALID_LIB "Error: Invalid file extension"
#define USAGE "\nUSAGE:\n\t./pacman [lib_path].so"

#define ERROR_LIB "Error: dlopen failed"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
