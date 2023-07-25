cmake_minimum_required(VERSION 3.5)
project(WebBaseGame)

add_executable(Donut main.cpp)

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
target_link_libraries(Donut PRIVATE SDL3::SDL3)