cmake_minimum_required(VERSION 3.21)
project(GOD LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Use the system raylib (MSYS2: pacman -S mingw-w64-x86_64-raylib).
# If it isn't installed, fall back to downloading and building raylib 5.5.
find_package(raylib 5.5 QUIET)
if(NOT raylib_FOUND)
    message(STATUS "System raylib not found - fetching raylib 5.5")
    include(FetchContent)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(BUILD_GAMES    OFF CACHE BOOL "" FORCE)
    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG        5.5
        GIT_SHALLOW    TRUE
    )
    FetchContent_MakeAvailable(raylib)
endif()

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# Keep the console attached so printf/TraceLog output is visible while developing.
# Flip to TRUE for a windows-only release build.
set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE FALSE)
