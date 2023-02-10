cmake_minimum_required(VERSION 3.15)

project(SnakeGame 
    VERSION 0.1 
    DESCRIPTION "Terminal-based game of Snake"
    LANGUAGES CXX
)

add_executable(app)

add_executable(app main.cpp)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

target_link_libraries(app PRIVATE CONAN_PKG::sfml CONAN_PKG::gtest)

target_compile_features(app PRIVATE cxx_std_17)

target_compile_options(app PRIVATE -Wall -Wextra -Werror)