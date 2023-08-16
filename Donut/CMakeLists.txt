cmake_minimum_required(VERSION 3.12)

project(Donut)

#find_package(box2d REQUIRED CONFIG COMPONENTS box2d)
find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
find_package(PkgConfig REQUIRED)

pkg_check_modules(GLEW REQUIRED glew)

set(DONUT_ASSETS_DIR ${CMAKE_SOURCE_DIR}/assets)
set(DONUT_SHADERS_DIR ${CMAKE_SOURCE_DIR}/shaders) 
set(DONUT_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

set(DONUT_SOURCE_DIR ${PROJECT_SOURCE_DIR})

configure_file(${DONUT_SOURCE_DIR}/Donut.h.in ${DONUT_INCLUDE_DIR}/Donut/Donut.h)

add_library(DonutShared SHARED
    Utils.cpp
    Donut.cpp
    Donut_ShadderSource.cpp
    Donut_GL_Program.cpp
    Donut_GL.cpp
    stb_image.cpp
    Donut_GL_TextureProgram.cpp
    Donut_GL_TextureVAO.cpp
    Donut_GL_Texture.cpp
    Donut_GL_Utils.cpp
    Donut_Camera.cpp
    Donut_GL_VAO.cpp
)

target_include_directories(DonutShared PUBLIC ${DONUT_INCLUDE_DIR})

target_link_libraries(DonutShared PUBLIC 
    SDL2::SDL2
    #box2d::box2d
    ${GLEW_LIBRARIES})

