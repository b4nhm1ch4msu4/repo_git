cmake_minimum_required(VERSION 3.30.4)

project(tetris)

include_directories(includes)

file(GLOB SOURCES "src/*.cpp" "main.cpp")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} raylib)
