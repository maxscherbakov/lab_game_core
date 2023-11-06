cmake_minimum_required(VERSION 3.22.1)
project(lab_game_core)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

set(resources help.txt welcome.txt)
 
source_group("Resources" FILES ${resources})

add_executable(MyLabGame map.cpp player.cpp professor.cpp area.cpp shop.cpp
                building.cpp student.cpp student-first.cpp student-genious.cpp
                main.cpp help.txt)
