target_sources(snake
    PUBLIC
        main.cpp

    PRIVATE
        Common.hpp
        Common.cpp
        Fruit.hpp
        Fruit.cpp
        Borders.hpp
        Borders.cpp
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