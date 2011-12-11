cmake_minimum_required (VERSION 2.6)

add_subdirectory(db)

set(MY_SRCS
    MainPlayer.hpp
    MainPlayer.cpp)

add_library(deck SHARED ${MY_SRCS})
