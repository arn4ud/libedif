cmake_minimum_required(VERSION 3.5) 

project(libedif)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2")

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

enable_testing()
add_subdirectory(src)
