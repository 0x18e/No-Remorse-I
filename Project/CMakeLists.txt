
# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.20)

project (NoRemorse)

# Include sub-projects.

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Recursively find all .cpp and .h files in the src directory
file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp" "${PROJECT_SOURCE_DIR}/src/*.h")

# Create an executable named NoRemorse
add_executable(NoRemorse ${SOURCES})

# Fetch SDL2
include(FetchContent)

FetchContent_Declare(
  SDL2
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG release-2.28.4
)

FetchContent_MakeAvailable(SDL2)

# Fetch SDL2_image
set(SDL2IMAGE_INSTALL OFF CACHE BOOL "" FORCE)  # Disable the installation step
FetchContent_Declare(
  SDL2_image
  GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
  GIT_TAG release-2.6.3  # Replace with the latest stable release if needed
)

FetchContent_MakeAvailable(SDL2_image)

# Link SDL2 and SDL2_image with your project
target_link_libraries(NoRemorse PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2_image::SDL2_image)

if(WIN32)
    add_custom_command(TARGET NoRemorse POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "$<TARGET_FILE:SDL2>"  # SDL2.dll
            "$<TARGET_FILE_DIR:NoRemorse>"  # Output directory
    )
    add_custom_command(TARGET NoRemorse POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "$<TARGET_FILE:SDL2_image>"  # SDL2_image.dll
            "$<TARGET_FILE_DIR:NoRemorse>"  # Output directory
    )
endif()

# Copy sprites folder to the output directory
add_custom_command(TARGET NoRemorse POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/sprites" "$<TARGET_FILE_DIR:NoRemorse>/sprites"
)
