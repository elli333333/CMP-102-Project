cmake_minimum_required(VERSION 3.16)
project(CMP102_Week6)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 20)

add_executable(CMP102_Week6
        main.cpp
        Player.h
        Player.cpp
        Match.cpp
        Match.h)

target_link_libraries(CMP102_Week6 ${CURSES_LIBRARIES})