cmake_minimum_required(VERSION 3.15)

project(SnakeGame 
    VERSION 0.1 
    DESCRIPTION "Terminal-based game of Snake"
    LANGUAGES CXX
)

add_executable(app)

target_include_directories(app PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_sources(app
    PUBLIC
        main.cpp
    PRIVATE
        "${PROJECT_SOURCE_DIR}/include/Fruit.hpp"
        "${PROJECT_SOURCE_DIR}/src/Fruit.cpp"
        "${PROJECT_SOURCE_DIR}/include/Common.hpp"
)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

target_link_libraries(app PRIVATE CONAN_PKG::sfml CONAN_PKG::gtest)

target_compile_features(app PRIVATE cxx_std_17)

target_compile_options(app PRIVATE -Wall -Wextra -Werror)