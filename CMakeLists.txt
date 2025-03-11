cmake_minimum_required(VERSION 3.10)
project(btrack VERSION 1.0)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-fsanitize=address -Wall -Werror -pedantic -g -O0")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-O2")

add_executable(btrack src/main.cpp src/display/main_menu.cpp src/display/curses_subsystem.cpp src/display/screen.cpp)

target_link_libraries(btrack ${CURSES_LIBRARIES})
