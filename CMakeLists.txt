# cmake_minimum_required(VERSION <specify CMake version here>)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled1 cmake-build-debug/main.cpp cmake-build-debug/playertype.h cmake-build-debug/card.h cmake-build-debug/card.cpp cmake-build-debug/bet.cpp cmake-build-debug/bet.h cmake-build-debug/game.cpp cmake-build-debug/game.h)