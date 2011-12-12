cmake_minimum_required (VERSION 2.6)

set(MY_SRCS
    db/Database.hpp
    db/Database.cpp
    MainPlayer.hpp
    MainPlayer.cpp)

add_library(deck SHARED ${MY_SRCS})
