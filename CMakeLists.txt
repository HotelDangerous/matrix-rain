cmake_minimum_required(VERSION 3.15)
project(matrix-rain LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(matrix-rain
    main.cpp
    src/streams/stream_character.cpp
    src/streams/stream.cpp
)

target_include_directories(matrix-rain PUBLIC include)
