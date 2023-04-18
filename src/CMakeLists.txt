cmake_minimum_required(VERSION 3.25)
project(Pacman_Sources)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)
add_library(Pacman_library SHARED)
add_library(LibSFML SHARED)

# libPacman

set_target_properties(
        Pacman_library
        PROPERTIES
        PREFIX ""
)

target_sources(
        Pacman_library
        PRIVATE
        Pacman/Map.cpp
        Pacman/Pacman.cpp
)

target_link_libraries(Pacman_library sfml-graphics sfml-window sfml-system)

# libSFML

set_target_properties(
        LibSFML
        PROPERTIES
        PREFIX ""
)

target_sources(
        LibSFML
        PRIVATE
        Graphical/Graphical.cpp
)

target_link_libraries(LibSFML sfml-graphics sfml-window sfml-system)
