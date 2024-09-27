# Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Project name
project(cppHeader)

# Specify the C++ standard
# set(CMAKE_CXX_STANDARD 17)

# Include directories for header files
include_directories(include)

# Collect all source files in the src directory
file(GLOB SOURCES "src/*.cpp")

# Set the output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Create the executable file, linking the sources with the main.cpp
add_executable(main main.cpp ${SOURCES})

