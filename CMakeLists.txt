cmake_minimum_required(VERSION 3.20)
project(Labyrinth C)

set(CMAKE_C_STANDARD 99)

add_executable(Labyrinth main.c types.h jatek.c jatek.h)
