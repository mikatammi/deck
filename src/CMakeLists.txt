cmake_minimum_required (VERSION 2.6)

add_subdirectory(libdeck)

if(NOT ANDROID)
add_subdirectory(deckqt)
endif()
