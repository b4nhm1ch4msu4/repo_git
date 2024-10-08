cmake_minimum_required(VERSION 3.30.4)

project(CSV_Handler)

# tích hợp các files header vào môi trường build
include_directories(include)

# gán biến SOURCES thay cho các file sources set(SOURCES src/CSV_Handler.cpp
# main.cpp) sử dụng regex với projects có nhiều file sources
file(GLOB SOURCES "src/*.cpp" "main.cpp")

# redirect executable file to bin sub-folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(CSV_Handler ${SOURCES})
