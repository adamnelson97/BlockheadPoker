# cmake_minimum_required(VERSION <specify CMake version here>)
project(BlockheadPoker)

set(CMAKE_CXX_STANDARD 14)

add_executable(BlockheadPoker cmake-build-debug/main.cpp cmake-build-debug/playertype.h cmake-build-debug/card.h cmake-build-debug/card.cpp cmake-build-debug/bet.cpp cmake-build-debug/bet.h cmake-build-debug/game.cpp cmake-build-debug/game.h cmake-build-debug/hand.cpp cmake-build-debug/hand.h cmake-build-debug/bethistory.cpp cmake-build-debug/bethistory.h cmake-build-debug/player.cpp cmake-build-debug/player.h cmake-build-debug/humanplayer.cpp cmake-build-debug/humanplayer.h cmake-build-debug/alphaplayer.cpp cmake-build-debug/alphaplayer.h)