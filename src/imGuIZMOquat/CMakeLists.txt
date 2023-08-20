cmake_minimum_required(VERSION 3.12)

add_library(imGuIZMOquat SHARED
    imGuIZMOquat.cpp)


set(IMGUIZMO_IMGUI_FOLDER "")


target_compile_definitions(imGuIZMOquat PRIVATE -DIMGUIZMO_IMGUI_FOLDER=${IMGUIZMO_IMGUI_FOLDER})

target_include_directories(imGuIZMOquat PUBLIC
    ${DONUT_GLOBAL_INCLUDE_DIR})

target_link_libraries(imGuIZMOquat PRIVATE imgui)

