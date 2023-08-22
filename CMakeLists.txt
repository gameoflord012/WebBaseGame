cmake_minimum_required(VERSION 3.15)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")
project(WebBaseGame)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -fdiagnostics-color=always -Wfatal-errors")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
set(CMAKE_VERBOSE_MAKEFILE ON)
 
set(DONUT_GLOBAL_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

find_package(Catch2 3 REQUIRED CONFIG)

add_subdirectory(src/Donut)
add_subdirectory(src/demos)
add_subdirectory(src/ImGuizmo)
add_subdirectory(libs)

add_executable(mygame main.cpp)
add_executable(tests test.cpp)

target_link_libraries(tests PRIVATE DonutShared Catch2::Catch2WithMain)
target_link_libraries(mygame PRIVATE DonutShared)



