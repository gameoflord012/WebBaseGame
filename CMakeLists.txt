cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
set(CMAKE_VERBOSE_MAKEFILE ON)

project(WebBaseGame)

find_package(Catch2 3 REQUIRED CONFIG)

find_package(box2d REQUIRED CONFIG COMPONENTS box2d)

find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)
find_package(SDL2_image REQUIRED CONFIG)

find_package(PkgConfig REQUIRED)

set(DONUT_ASSETS_DIR "${CMAKE_SOURCE_DIR}/assets")
set(DONUT_SHADERS_DIR "${CMAKE_SOURCE_DIR}/shaders") 
set(DONUT_SOURCE_DIR "${CMAKE_SOURCE_DIR}/Donut")
set(DONUT_LIBS_DIR "${PROJECT_SOURCE_DIR}/libs")

configure_file(${DONUT_SOURCE_DIR}/Donut.h.in ${DONUT_SOURCE_DIR}/Donut.h)
pkg_check_modules(GLEW REQUIRED glew)

add_library(Donut_shared SHARED
    ${DONUT_SOURCE_DIR}/Utils.cpp
    ${DONUT_SOURCE_DIR}/Donut.cpp
    ${DONUT_SOURCE_DIR}/DONUT_ShadderSource.cpp
)

target_link_libraries(Donut_shared PUBLIC 
    SDL2::SDL2
    ${GLEW_LIBRARIES}
    SDL2_image::SDL2_image)

add_executable(mygame main.cpp)
add_executable(tests test.cpp)

target_link_libraries(tests PRIVATE Donut_shared Catch2::Catch2WithMain)
target_link_libraries(mygame PRIVATE box2d::box2d Donut_shared)


