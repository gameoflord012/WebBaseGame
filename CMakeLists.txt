cmake_minimum_required(VERSION 3.12)
set(CMAKE_VERBOSE_MAKEFILE ON)

project(WebBaseGame)

find_package(Catch2 3 REQUIRED)

find_package(box2d REQUIRED)

find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)
find_package(SDL2_image REQUIRED)

find_package(PkgConfig REQUIRED)

set(DONUT_ASSETS_DIR "${CMAKE_SOURCE_DIR}/assets")
set(DONUT_SOURCE_DIR "${CMAKE_SOURCE_DIR}/Donut")
set(DONUT_LIBS_DIR "${PROJECT_SOURCE_DIR}/libs")

configure_file(${DONUT_SOURCE_DIR}/Donut.h.in ${DONUT_SOURCE_DIR}/Donut.h)
pkg_check_modules(GLEW REQUIRED glew)

# These tests can use the Catch2-provided main
add_executable(tests test.cpp)

add_executable(Donut
    main.cpp
    ${DONUT_SOURCE_DIR}/Utils.cpp
    ${DONUT_SOURCE_DIR}/Donut.cpp
    ${DONUT_SOURCE_DIR}/DONUT_ShadderSource.cpp)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

target_link_libraries(Donut PRIVATE 
    SDL2::SDL2 
    SDL2_image::SDL2_image
    box2d
    ${GLEW_LIBRARIES})

