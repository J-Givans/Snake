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
        /// \brief Default constructor
        Snake();

        /// \brief Render the snake to the screen
        /// \param[in] window The window to which the snake will be rendered
        void render(sf::RenderWindow& window);

        /// \brief Move the snake in the direction it is facing
        void move();

        /// \brief Grow the snake
        /// \details Push a new segment onto the snake after it eats a fruit
        void grow();

        /// \brief Set the direction of the snake
        /// \param[in] d The new direction
        void setDirection(Direction d);

        /// \brief Determine if the snake has collided with itself
        void checkCollision();

    private:
        std::vector<sf::Vector2i> body { {5, 5}, {6, 5}, {7, 5} };
        Direction direction { Direction::None };
        sf::RectangleShape shape { sf::Vector2f(BlockSize - 1, BlockSize - 1) };

        /// \brief Shrink the snake whenever it eats itself
        void shrink(std::ptrdiff_t segments);
    };
}

#endif