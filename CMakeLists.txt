cmake_minimum_required(VERSION 3.11)
project(Minesweeper C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

include(ProcessorCount)
ProcessorCount(N)
if(N STRGREATER "1")
    set(CMAKE_BUILD_PARALLEL_LEVEL ${N} CACHE STRING "Parallel build level")
    set(CMAKE_MAKE_PROGRAM_FLAGS "-j${N}" CACHE STRING "Make flags")
endif()

include(FetchContent)
FetchContent_Declare(
  raylib
  GIT_REPOSITORY https://github.com/raysan5/raylib.git
  GIT_TAG        master
)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(raylib)

include_directories(include)

set(SOURCES src/main.c src/minesweeper.c)
add_executable(minesweeper ${SOURCES})

if(WIN32)
    target_link_libraries(minesweeper raylib winmm gdi32)
else()
    target_link_libraries(minesweeper raylib m pthread dl)
endif()

add_custom_command(TARGET minesweeper POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/resources
    ${CMAKE_BINARY_DIR}/resources)

add_custom_target(run
    COMMAND $<TARGET_FILE:minesweeper>
    DEPENDS minesweeper
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)