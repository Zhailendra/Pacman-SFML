cmake_minimum_required(VERSION 3.25)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
project(Pacman_SFML)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

include_directories(include)

add_executable(pacman
        main.cpp
        )

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})

add_subdirectory(src include)