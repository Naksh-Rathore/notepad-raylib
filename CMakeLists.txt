cmake_minimum_required(VERSION 3.24)
project(notepad-raylib LANGUAGES C)

# Force raylib to skip building its own examples and tests
set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
set(BUILD_TESTS OFF CACHE INTERNAL "")

# Include the FetchContent module
include(FetchContent)

# Declare raylib repository and target version
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG        5.5
)

# Download and make raylib targets available to the project
FetchContent_MakeAvailable(raylib)

# Collect all source and header files from the src directory
file(GLOB_RECURSE PROJECT_FILES
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)

# Define your project executable
add_executable(${PROJECT_NAME} ${PROJECT_FILES})

# Link your executable against the raylib library target
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# Optional: Enable standard C99 features
set_target_properties(${PROJECT_NAME} PROPERTIES
    C_STANDARD 99
    C_STANDARD_REQUIRED ON
)
