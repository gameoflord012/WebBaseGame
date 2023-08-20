cmake_minimum_required(VERSION 3.12)
project(DonutDemo)

find_package(glm REQUIRED)

add_executable(CameraDemo 
    camera_demo.cpp)

add_executable(ImguiDemo
    imgui_setup_demo.cpp)

target_link_libraries(CameraDemo PRIVATE DonutShared glm::glm)
target_link_libraries(ImguiDemo PRIVATE DonutShared)
