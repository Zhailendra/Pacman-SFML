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
#include <vector>
#include <array>

/* Class */

#include "IGraphical.hpp"
#include "IPacman.hpp"
#include "IMap.hpp"
#include "Type.hpp"
#include "Exception.hpp"
#include "Map.hpp"

/* Defines */

#define INVALID_ARG "Error: Invalid number of arguments"
#define INVALID_LIB "Error: Invalid file extension"
#define USAGE "\nUSAGE:\n\t./pacman [lib_path].so"

#define ERROR_LIB "Error: dlopen failed"
#define ERROR_SYM "Error: dlsym failed"
#define ERROR_SYMBOL "Error: cannot load symbol 'graphical_constructor': "

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

#define MAP_ASSETS "./assets/Map.png"
