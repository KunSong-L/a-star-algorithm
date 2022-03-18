cmake_minimum_required(VERSION 2.8.3)

project(Astar)

add_compile_options(-std=c++11 -O2)

add_executable(test test.cpp astar/astar.h astar/astar.cpp astar/blockallocator.cpp astar/blockallocator.h)