cmake_minimum_required (VERSION 2.6)

find_package(Protobuf 2.3.0 REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIR})

set(Boost_USE_MULTITHREADED ON)
find_package(Boost 1.48.0 REQUIRED COMPONENTS system filesystem thread unit_test_framework)
include_directories(${Boost_INCLUDE_DIRS})

include(FindPkgConfig)
pkg_search_module(TAGLIB REQUIRED taglib)

set(LIBDECK_PROTOS
    db/Database.proto
    connection/Connection.proto
)

set(LIBDECK_SRCS
    db/Database.cpp
    db/Database.hpp
    db/DatabaseManager.cpp
    db/DatabaseManager.hpp
    db/Artist.cpp
    db/Artist.hpp
    db/Album.cpp
    db/Album.hpp
    db/Track.cpp
    db/Track.hpp
    db/TrackSet.cpp
    db/TrackSet.hpp
    db/TrackSourceInfo.cpp
    db/TrackSourceInfo.hpp
    db/PlayList.cpp
    db/PlayList.hpp
    db/scanner/ScannerTrackInfo.cpp
    db/scanner/ScannerTrackInfo.hpp
    db/scanner/Scanner.cpp
    db/scanner/Scanner.hpp
    db/scanner/ScannerManager.cpp
    db/scanner/ScannerManager.hpp
    connection/Connection.cpp
    connection/Connection.hpp
    connection/Server.cpp
    connection/Server.hpp
    connection/Service.cpp
    connection/Service.hpp
    connection/DatabaseService.cpp
    connection/DatabaseService.hpp
    connection/FileService.cpp
    connection/FileService.hpp
    connection/ConnectionManager.cpp
    connection/ConnectionManager.hpp
    audio/output/AbstractAudioOutput.cpp
    audio/output/AbstractAudioOutput.hpp
    audio/output/DummyAudioOutput.cpp
    audio/output/DummyAudioOutput.hpp
    audio/output/OpenALOutput.cpp
    audio/output/OpenALOutput.hpp
    audio/output/OpenSLESOutput.cpp
    audio/output/OpenSLESOutput.hpp
    audio/decoder/AbstractAudioDecoder.cpp
    audio/decoder/AbstractAudioDecoder.hpp
    audio/decoder/FAADDecoder.cpp
    audio/decoder/FAADDecoder.hpp
    audio/decoder/FLACDecoder.cpp
    audio/decoder/FLACDecoder.hpp
    audio/decoder/MADDecoder.cpp
    audio/decoder/MADDecoder.hpp
    audio/decoder/VorbisDecoder.cpp
    audio/decoder/VorbisDecoder.hpp
    audio/decoder/FFmpegDecoder.cpp
    audio/decoder/FFmpegDecoder.hpp
    audio/source/AbstractAudioFileSource.cpp
    audio/source/AbstractAudioFileSource.hpp
    audio/source/LocalFileSource.cpp
    audio/source/LocalFileSource.hpp
    audio/source/ConnectionFileSource.cpp
    audio/source/ConnectionFileSource.hpp
    audio/source/HTTPFileSource.cpp
    audio/source/HTTPFileSource.hpp
    audio/encoder/AbstractAudioEncoder.cpp
    audio/encoder/AbstractAudioEncoder.hpp
    audio/encoder/VorbisEncoder.cpp
    audio/encoder/VorbisEncoder.hpp
    audio/AudioManager.cpp
    audio/AudioManager.hpp
    MainPlayer.cpp
    MainPlayer.hpp
    ${LIBDECK_PROTOS}
)

# Protobuf generation
PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS ${LIBDECK_PROTOS})

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${TAGLIB_INCLUDE_DIRS})

add_library(deck SHARED ${LIBDECK_SRCS} ${PROTO_SRCS} ${PROTO_HDRS})

target_link_libraries(deck ${Boost_LIBRARIES})
target_link_libraries(deck ${PROTOBUF_LIBRARY})
target_link_libraries(deck ${TAGLIB_LIBRARIES})
