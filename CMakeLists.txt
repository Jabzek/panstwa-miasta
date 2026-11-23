cmake_minimum_required(VERSION 3.16)
project(PanstwaMiastaServer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCES
    server/src/main.cpp
    server/src/utils.cpp
    server/src/network.cpp
)

add_executable(server ${SOURCES})
target_include_directories(server PRIVATE server/include)
target_compile_options(server PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)

file(COPY server/data DESTINATION ${CMAKE_BINARY_DIR})