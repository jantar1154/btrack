cmake_minimum_required(VERSION 3.10)
project(btrack VERSION 1.0)

find_package(Curses REQUIRED)
find_package(SQLite3 REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
include_directories(${SQLite3_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} -fsanitize=address -Wall -Werror -pedantic -O0 -g")

add_executable(btrack src/main.cpp src/util.cpp src/app.cpp src/display/curses_subsystem.cpp src/display/screen.cpp src/display/menu.cpp src/display/menu_item.cpp src/spending_data.cpp src/sql.cpp)

target_link_libraries(btrack ${CURSES_LIBRARIES})
target_link_libraries(btrack ${SQLite3_LIBRARIES})
