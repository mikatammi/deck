cmake_minimum_required (VERSION 2.6)
project (deck)

set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -pedantic" )

ENABLE_TESTING()

add_subdirectory(src)

if(NOT ANDROID)
    add_subdirectory(tests)
endif()
