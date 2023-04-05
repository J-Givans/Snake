#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "Common.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

#include <vector>


namespace snake::snake
{
    enum class Direction { None, Up, Down, Left, Right };

    class Snake
    {
    public:
        std::vector<sf::Vector2i> body { {5, 5}, {6, 5}, {7, 5} };
        Direction direction { Direction::None };
        sf::RectangleShape shape { sf::Vector2f(BlockSize - 1, BlockSize - 1) };

        /// \brief Default constructor
        Snake();

        /// \brief Render the snake to the screen
        /// \param[in] window The window to which the snake will be rendered
        void render(sf::RenderWindow& window);
    };
}

#endif