cmake_minimum_required (VERSION 2.6)

find_package(Qt4 REQUIRED QtCore QtGui phonon)
include(${QT_USE_FILE})

set(DECKQT_SRCS
    MainWindow.cpp
    DatabaseWidget.cpp
    TrackSetModel.cpp
    TrackControlWidget.cpp
    PlayListWidget.cpp
    PlayListView.cpp
    PlayListModel.cpp
    OptionsDialog.cpp
    GenericOptionsWidget.cpp
    DatabaseOptionsWidget.cpp
    PeerOptionsWidget.cpp
    main.cpp
)

set(DECKQT_MOC_HDRS
    MainWindow.hpp
    DatabaseWidget.hpp
    TrackSetModel.hpp
    TrackControlWidget.hpp
    PlayListWidget.hpp
    PlayListView.hpp
    PlayListModel.hpp
    OptionsDialog.hpp
    GenericOptionsWidget.hpp
    DatabaseOptionsWidget.hpp
    PeerOptionsWidget.hpp
)

set(DECKQT_UIS
    MainWindow.ui
    DatabaseWidget.ui
    TrackControlWidget.ui
    PlayListWidget.ui
    OptionsDialog.ui
    GenericOptionsWidget.ui
    DatabaseOptionsWidget.ui
    PeerOptionsWidget.ui
)

QT4_WRAP_CPP(DECKQT_MOC_SRCS ${DECKQT_MOC_HDRS})
QT4_WRAP_UI(DECKQT_UI_HDRS ${DECKQT_UIS})

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../libdeck)

add_executable(deckqt ${DECKQT_SRCS} ${DECKQT_MOC_SRCS} ${DECKQT_UI_HDRS})

target_link_libraries(deckqt ${QT_LIBRARIES})
target_link_libraries(deckqt deck)
