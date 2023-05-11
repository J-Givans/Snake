add_executable(snake)

target_include_directories(snake PUBLIC "${PROJECT_SOURCE_DIR}/include")

target_sources(snake
    PUBLIC
        main.cpp
        "${PROJECT_SOURCE_DIR}/include/Borders.hpp"
        "${PROJECT_SOURCE_DIR}/include/Common.hpp"
        "${PROJECT_SOURCE_DIR}/include/Fruit.hpp"
        "${PROJECT_SOURCE_DIR}/include/Snake.hpp"
    PRIVATE
        Common.cpp
        Fruit.cpp
        Borders.cpp
        Snake.cpp
)

target_link_libraries(snake
    PRIVATE
        sfml-system
        sfml-window
        sfml-graphics
)

target_compile_features(snake 
    PRIVATE 
        cxx_std_17
)

target_compile_options(snake
    PRIVATE
        -Wall -Wextra -Werror -Wundef
)