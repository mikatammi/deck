cmake_minimum_required (VERSION 2.6)
project (deck)

set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -pedantic" )

ENABLE_TESTING()

if(DEFINED ANDROID)
    add_definitions(-DANDROID)
endif()

if(DEFINED APPLE)
    add_definitions(-DAPPLE)
endif()

if(DEFINED UNIX)
    add_definitions(-DUNIX)
endif()

if(DEFINED WIN32)
    add_definitions(-DWINDOWS)
endif()

# TODO: Add -DLINUX check

add_subdirectory(src)

if(NOT ANDROID)
    add_subdirectory(tests)
endif()
