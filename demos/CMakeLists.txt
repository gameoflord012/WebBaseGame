cmake_minimum_required(VERSION 3.12)
project(DonutDemo)

add_executable(CameraDemo camera_demo.cpp)

target_link_libraries(CameraDemo PRIVATE DonutShared)
