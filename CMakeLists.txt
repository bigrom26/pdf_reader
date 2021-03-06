cmake_minimum_required(VERSION 3.12)

project(pdf_reader)

set(CMAKE_CXX_STANDARD 17)

set(BINARY_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BINARY_DIRECTORY})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BINARY_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BINARY_DIRECTORY})

add_subdirectory(libs/mupdf_wrapper)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(SOURCE_FILES_DIRECTORY src)

set(SOURCE_FILES
    ${SOURCE_FILES_DIRECTORY}/document.h
    ${SOURCE_FILES_DIRECTORY}/document.cpp
    ${SOURCE_FILES_DIRECTORY}/main.cpp
    ${SOURCE_FILES_DIRECTORY}/pdf_reader.cpp
    ${SOURCE_FILES_DIRECTORY}/pdf_reader.h
    ${SOURCE_FILES_DIRECTORY}/single_page_view.h
    ${SOURCE_FILES_DIRECTORY}/single_page_view.cpp
)

set(FORM_FILES
    ${SOURCE_FILES_DIRECTORY}/pdf_reader.ui
)

set(RESOURCE_FILES
    ${SOURCE_FILES_DIRECTORY}/pdf_reader.qrc
)

add_executable(pdf_reader
    ${SOURCE_FILES}
    ${FORM_FILES}
    ${RESOURCE_FILES}
)

add_definitions(
    -DQT_DEPRECATED_WARNINGS
)

target_link_libraries(pdf_reader
    PRIVATE
    mupdf_wrapper
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    stdc++fs
)
