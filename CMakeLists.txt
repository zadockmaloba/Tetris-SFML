cmake_minimum_required(VERSION 3.5)

project(Tetris-SFML LANGUAGES CXX)
set(EXECUTABLE_NAME "Tetris-SFML")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML REQUIRED system window graphics network audio)

add_executable(Tetris-SFML
    main.cpp
    variabledefs.h
    board.h
    board.cpp
    graphics.h
    graphics.cpp
    blockobject.h
    blockobject.cpp
    logic.h
    logic.cpp
)

target_link_libraries(${EXECUTABLE_NAME}
    sfml-window
    sfml-system
    sfml-graphics
    sfml-network
    sfml-audio
)
