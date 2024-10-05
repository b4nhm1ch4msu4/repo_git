cmake_minimum_required(VERSION 3.30.4)

project(tetris)

set(RAYLIB_DIR "E:/Programs/raylib")

include_directories(includes)
include_directories(${RAYLIB_DIR}/src)

add_library(raylib STATIC IMPORTED)
set_target_properties(raylib PROPERTIES IMPORTED_LOCATION
                                        "${RAYLIB_DIR}/src/libraylib.a")

file(GLOB SOURCES "src/*.cpp" "main.cpp")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} raylib winmm gdi32)
