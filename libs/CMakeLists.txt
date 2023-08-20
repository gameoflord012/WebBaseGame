cmake_minimum_required(VERSION 3.12)

set(IMGUI_LIB_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/imgui)

add_library(imgui SHARED 
    ${IMGUI_LIB_DIRECTORY}/imgui_draw.cpp
    ${IMGUI_LIB_DIRECTORY}/imgui_tables.cpp
    ${IMGUI_LIB_DIRECTORY}/imgui.cpp
    ${IMGUI_LIB_DIRECTORY}/imgui_widgets.cpp
    ${IMGUI_LIB_DIRECTORY}/imgui_demo.cpp
    
    ${IMGUI_LIB_DIRECTORY}/backends/imgui_impl_sdl2.cpp
    ${IMGUI_LIB_DIRECTORY}/backends/imgui_impl_opengl3.cpp)

target_include_directories(imgui PUBLIC
    ${IMGUI_LIB_DIRECTORY}/
    ${IMGUI_LIB_DIRECTORY}/backends/
    )