cmake_minimum_required(VERSION 3.5)
project(WebBaseGame)

find_package(Catch2 3 REQUIRED)

find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)
find_package(SDL2_image REQUIRED)

set(DONUT_ASSETS_DIR "${CMAKE_SOURCE_DIR}/assets")
configure_file(${CMAKE_SOURCE_DIR}/donut.h.in ${CMAKE_SOURCE_DIR}/donut.h)


# These tests can use the Catch2-provided main
add_executable(tests test.cpp)
add_executable(Donut main.cpp utils.cpp donut.cpp)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

target_link_libraries(Donut PRIVATE SDL2::SDL2 SDL2_image::SDL2_image)
target_link_libraries(Donut PRIVATE SDL2::SDL2)

