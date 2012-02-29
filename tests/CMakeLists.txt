cmake_minimum_required (VERSION 2.6)

include_directories(../src/libdeck)

add_executable(test_scannertrackinfo test_scannertrackinfo.cpp)
add_executable(test_scanner test_scanner.cpp)
add_executable(test_settings test_settings.cpp)

target_link_libraries(test_scannertrackinfo deck)
target_link_libraries(test_scanner deck)
target_link_libraries(test_settings deck)

add_test(scannertrackinfo
        ${CMAKE_CURRENT_BINARY_DIR}/test_scannertrackinfo)
add_test(scanner
        ${CMAKE_CURRENT_BINARY_DIR}/test_scanner)
add_test(settings
        ${CMAKE_CURRENT_BINARY_DIR}/test_settings)
