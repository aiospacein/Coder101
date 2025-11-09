# Root CMakeLists.txt for CODE_PRACTICE project
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(CODE_PRACTICE)

# Set the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Set build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Debug flags
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-g -gdwarf-4 -O0)
    add_compile_definitions(DEBUG)
else()
    add_compile_options(-O2)
endif()

# Add the Exercise subdirectory
add_subdirectory(Exercise)

# Print build information
message(STATUS "Building CODE_PRACTICE project")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C standard: ${CMAKE_C_STANDARD}")