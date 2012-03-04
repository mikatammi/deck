cmake_minimum_required (VERSION 2.6)
project (deck)

set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -pedantic" )

ENABLE_TESTING()

set(BOOSTCOMPONENTS system filesystem thread)

if(NOT ANDROID)
    set(BOOSTCOMPONENTS ${BOOSTCOMPONENTS} unit_test_framework)
endif()

set(Boost_USE_MULTITHREADED ON)
find_package(Boost 1.45.0 REQUIRED COMPONENTS ${BOOSTCOMPONENTS})
include_directories(${Boost_INCLUDE_DIRS})

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
