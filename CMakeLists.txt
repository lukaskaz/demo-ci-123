cmake_minimum_required(VERSION 3.10)
project(demo)

set(CMAKE_CXX_STANDARD 20)

include_directories(src)
include_directories(tst)

add_subdirectory(src)
add_subdirectory(tst)

