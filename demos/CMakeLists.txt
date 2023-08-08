cmake_minimum_required(VERSION 3.12)
project(DonutDemo)

add_executable(Demos camera_demo.cpp)

target_link_libraries(Demos PRIVATE DonutShared)
