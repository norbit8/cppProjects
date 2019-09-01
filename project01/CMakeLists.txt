cmake_minimum_required(VERSION 3.12)
project(project01)

include_directories(/cs/usr/yoav/semester03/cpp/cppProjects/project01/lib/pkgconfig)

find_library(ex1_lib project01)

#grouping the libraries
set(frameworks ${ex1_lib})

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(SOURCE_FILES ex1_cpp_tester_v1.2.cpp)

add_executable(project01 GField.cpp GFNumber.cpp IntegerFactorization.cpp ex1_cpp_tester_v1.2.cpp)

target_link_libraries(project01 gtest gtest_main)