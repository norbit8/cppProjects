cmake_minimum_required(VERSION 3.12)
project(project01)

set(CMAKE_CXX_STANDARD 14)

add_executable(project01 main.cpp GField.cpp GField.h GFNumber.cpp GFNumber.h IntegerFactorization.cpp)