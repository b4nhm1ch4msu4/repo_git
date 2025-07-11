cmake_minimum_required(VERSION 3.30.4)

project(hello)

include_directories(include)

# set(SOURCES src/hello.cpp main.cpp)
file(GLOB SOURCES "src/*.cpp" "main.cpp")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(hello ${SOURCES})
