cmake_minimum_required(VERSION 3.13)
project(dijkstra_algorithm C)

set(CMAKE_C_STANDARD 99)

add_executable(dijkstra_algorithm main.c dijkstra.c dijkstra.h)