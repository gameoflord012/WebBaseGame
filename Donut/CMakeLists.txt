cmake_minimum_required(VERSION 3.12)

project(Donut)

find_package(box2d REQUIRED CONFIG COMPONENTS box2d)
find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
find_package(SDL2_image REQUIRED CONFIG)
find_package(PkgConfig REQUIRED)

pkg_check_modules(GLEW REQUIRED glew)

set(DONUT_ASSETS_DIR "${CMAKE_SOURCE_DIR}/assets")
set(DONUT_SHADERS_DIR "${CMAKE_SOURCE_DIR}/shaders") 
set(DONUT_SOURCE_DIR "${CMAKE_SOURCE_DIR}/Donut")
set(DONUT_LIBS_DIR "${PROJECT_SOURCE_DIR}/libs")

configure_file(${DONUT_SOURCE_DIR}/Donut.h.in ${DONUT_SOURCE_DIR}/Donut.h)


add_library(DonutShared SHARED
    ${DONUT_SOURCE_DIR}/Utils.cpp
    ${DONUT_SOURCE_DIR}/Donut.cpp
    ${DONUT_SOURCE_DIR}/Donut_ShadderSource.cpp
    #${Donut_SOURCE_DIR}/Donut_GL_DrawLineProgram.cpp
)

target_include_directories(DonutShared PUBLIC ${PROJECT_SOURCE_DIR})

target_link_libraries(DonutShared PUBLIC 
    SDL2::SDL2
    box2d::box2d
    ${GLEW_LIBRARIES}
    SDL2_image::SDL2_image)

