# pdf_reader
[![CircleCI](https://circleci.com/gh/antonioborondo/pdf_reader.svg?style=svg)](https://circleci.com/gh/antonioborondo/pdf_reader)

![Screenshot](resources/screenshot.png?raw=true)

## Features
- Cross-platform (Windows/Linux/MacOS) PDF reader.
- GUI implemented with Qt: https://www.qt.io
- GUI icons from elementary OS: https://github.com/elementary/icons
- PDF rendering implemented with MuPDF: https://www.mupdf.com
- MuPDF fully integrated in CMake as an external project.
- MuPDF wrapped in a C++ library following the RAII technique.
- BDD unit tests implemented with Catch2: https://github.com/catchorg/Catch2
- CI implemented with CircleCI: https://www.circleci.com

## Windows (MinGW 64-bit)
1. Install MSYS2: https://www.msys2.org
1. Run `mingw64.exe`
1. Install packages:
    ```
    pacman -S git mingw-w64-x86_64-cmake make mingw-w64-x86_64-make mingw-w64-x86_64-gcc mingw-w64-x86_64-qt5
    ```
    NOTE: Recommended extra packages for development:
    ```
    pacman -S mingw-w64-x86_64-gdb mingw-w64-x86_64-qt-creator
    ```
1. Clone repository
1. Configure, build and test project:
    ```
    mkdir pdf_reader_cmake/
    cd pdf_reader_cmake/
    cmake -G "MinGW Makefiles" -DCMAKE_SH=CMAKE_SH-NOTFOUND ../pdf_reader
    cmake --build .
    ctest -V
    ```
1. Run application:
    ```
    cd bin/
    ./pdf_reader.exe
    ```

## Linux (Ubuntu 18.04 LTS 64-bit)
1. Install packages:
    ```
    sudo apt-get install git cmake g++ qt5-default
    ```
    NOTE: Recommended extra package for development:
    ```
    sudo apt-get install qtcreator
    ```
1. Clone repository
1. Configure, build and test project:
    ```
    mkdir pdf_reader_cmake/
    cd pdf_reader_cmake/
    cmake ../pdf_reader
    cmake --build .
    ctest -V
    ```
1. Run application:
    ```
    cd bin/
    ./pdf_reader
    ```

