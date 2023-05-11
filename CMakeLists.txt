cmake_minimum_required(VERSION 3.20)

project(Snake
    VERSION 0.1.1
    DESCRIPTION "The snake game"
    LANGUAGES CXX
)

find_program(CCACHE ccache)

if (CCACHE)
    message("Found ccache")
    set(CMAKE_CXX_COMPILER_LAUNCHER "${CCACHE}")
endif()

add_subdirectory(src)