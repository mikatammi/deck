cmake_minimum_required (VERSION 2.6)

set(MY_SRCS
    db/Database.hpp
    db/Database.cpp
    db/Database.proto
    db/DatabaseManager.cpp
    db/DatabaseManager.hpp
    db/Track.cpp
    db/Track.hpp
    db/TrackSet.cpp
    db/TrackSet.hpp
    MainPlayer.hpp
    MainPlayer.cpp
    Database.pb.h
    Database.pb.cc
)

# Protobuf generation
set_source_files_properties(Database.pb.cc Database.pb.h
    properties
    generated true)

add_custom_command(
    OUTPUT Database.pb.cc Database.pb.h
    COMMAND protoc db/Database.proto --cpp_out=${CMAKE_CURRENT_BINARY_DIR} --proto_path=db
    DEPENDS
    db/Database.proto
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${CMAKE_CURRENT_BINARY_DIR})
add_library(deck SHARED ${MY_SRCS})
