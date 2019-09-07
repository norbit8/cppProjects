cmake_minimum_required(VERSION 3.14)
project(project02)

set(CMAKE_CXX_STANDARD 14)
add_executable(project02 FractalDrawer.cpp Fractal.cpp Fractal.h)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
find_package(Boost COMPONENTS filesystem REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(project02 ${Boost_LIBRARIES})