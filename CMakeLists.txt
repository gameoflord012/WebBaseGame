cmake_minimum_required(VERSION 3.12)
project(WebBaseGame)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
set(CMAKE_VERBOSE_MAKEFILE ON)

find_package(Catch2 3 REQUIRED CONFIG)


add_subdirectory(Donut)

add_executable(mygame main.cpp)
add_executable(tests test.cpp)

target_link_libraries(tests PRIVATE DonutShared Catch2::Catch2WithMain)
target_link_libraries(mygame PRIVATE DonutShared)


