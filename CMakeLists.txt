cmake_minimum_required(VERSION 3.16)
project(Resonix)

find_package(SDL2 REQUIRED)

add_executable(Resonix src/main.cpp)

target_link_libraries(Resonix PRIVATE SDL2::SDL2)