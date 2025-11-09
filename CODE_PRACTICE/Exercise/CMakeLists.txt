# CMakeLists.txt for Exercise directory (subdirectory)
# Note: This is now a subdirectory, so cmake_minimum_required and project() are handled by parent

# Add executable for main program
add_executable(exercise_main
    src/main.c
    src/main.h
)

# Set output directory
set_target_properties(exercise_main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Add include directories
target_include_directories(exercise_main PRIVATE
    src
)

# Link math library if needed (for sqrt function)
target_link_libraries(exercise_main m)

# Optional: Add individual executables for other source files if needed
# Uncomment the following lines if you want to build separate executables for each file

# add_executable(prime_test
#     src/ds/src/prime_number.c
# )
# target_link_libraries(prime_test m)

# add_executable(reverse_test
#     src/ds/src/reverse_number.c
# )

# add_executable(heap_test
#     src/ds/src/heap.c
# )

# add_executable(stack_test
#     src/ds/src/stack.c
# )

# Print build information
message(STATUS "Building Exercise project")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C standard: ${CMAKE_C_STANDARD}")
