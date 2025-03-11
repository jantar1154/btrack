cmake_minimum_required(VERSION 3.10)
project(btrack VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-fsanitize=address -Wall -Werror -pedantic -g -O0")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-O2")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lncurses")

add_executable(btrack src/main.cpp src/display/main_menu.cpp src/display/curses_subsystem.cpp src/display/screen.cpp)
