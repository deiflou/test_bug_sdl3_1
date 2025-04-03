cmake_minimum_required(VERSION 3.20)

project(test_bug_sdl3 LANGUAGES C)

############################################
# SDL
############################################
include(FetchContent)
FetchContent_Declare(
    sdl3
    GIT_REPOSITORY
        https://github.com/libsdl-org/SDL.git
    GIT_TAG
        release-3.2.10
)
FetchContent_MakeAvailable(sdl3)

############################################
# Main program
############################################
add_executable(${CMAKE_PROJECT_NAME} main.c)
target_link_libraries(${CMAKE_PROJECT_NAME} SDL3::SDL3)
