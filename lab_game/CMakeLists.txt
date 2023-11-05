cmake_minimum_required(VERSION 3.22.1)
project(lab_game_core)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(MyLabGame main.cpp map.cpp player.cpp professor.cpp area.cpp shop.cpp
                building.cpp student.cpp student-first.cpp student-genious.cpp)
