cmake_minimum_required(VERSION 3.12)
project(DonutDemo)

find_package(glm REQUIRED)

add_executable(CameraDemo camera_demo.cpp)

target_link_libraries(CameraDemo PRIVATE DonutShared glm::glm)
