cmake_minimum_required(VERSION 3.22.1)
project(lab_game_core)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

file(GLOB RESOURCE CMAKE_CONFIGURE_DEPENDS
    ./*.cpp
)

add_executable(MyLabGame ${RESOURCE})
