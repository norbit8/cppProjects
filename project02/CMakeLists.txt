cmake_minimum_required(VERSION 3.14)
project(project02)

set(CMAKE_CXX_STANDARD 14)
add_executable(project02 FractalDrawer.cpp Fractal.cpp Fractal.h)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")