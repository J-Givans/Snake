add_executable(snake)

find_package(SFML 2.5.1 REQUIRED
    COMPONENTS
        sfml-system
        sfml-window
        sfml-graphics
)

find_package(Microsoft.GSL REQUIRED)

target_include_directories(snake PUBLIC "${PROJECT_SOURCE_DIR}/include")

target_link_libraries(snake
    PUBLIC
        sfml-system
        sfml-window
        sfml-graphics
    PRIVATE
        Microsoft.GSL::GSL
)

target_sources(snake
    PUBLIC
        main.cpp
        "${PROJECT_SOURCE_DIR}/include/Borders.hpp"
        "${PROJECT_SOURCE_DIR}/include/Common.hpp"
        "${PROJECT_SOURCE_DIR}/include/Fruit.hpp"
        "${PROJECT_SOURCE_DIR}/include/Snake.hpp"
        "${PROJECT_SOURCE_DIR}/include/World.hpp"
        "${PROJECT_SOURCE_DIR}/include/Game.hpp"
    PRIVATE
        Common.cpp
        Fruit.cpp
        Borders.cpp
        Snake.cpp
        World.cpp
        Game.cpp
)

target_compile_features(snake 
    PRIVATE 
        cxx_std_17
)

target_compile_options(snake
    PRIVATE
        -Wall -Wextra -Werror -Wundef
)