cmake_minimum_required(VERSION 3.14)
project(project02)

set(CMAKE_CXX_STANDARD 14)
add_executable(project02 FractalDrawer.cpp Fractal.cpp Fractal.h)

find_package(Boost COMPONENTS system filesystem REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(project02 ${Boost_LIBRARIES})