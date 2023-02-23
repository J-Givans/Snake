#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "Common.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

#include <vector>
#include <cstddef>

enum class Direction { None, Up, Down, Left, Right };

class Snake
{
    friend class Window;
public:
    Snake() noexcept;

    /**
     * @brief Get the direction which the head is facing
     * 
     * @return Direction const& The direction of the snake's head
     */
    Direction const& getDirection() const& noexcept;

    /**
     * @brief Get the direction which the head is facing
     * 
     * @return Direction The direction of the snake's head
     */
    Direction getDirection() && noexcept;

    /**
     * @brief Set the direction based on the key pressed
     * 
     */
    void setDirection() noexcept;

    /**
     * @brief Grow the snake whenever it eats a fruit
     * 
     */
    void grow() noexcept;

    /**
     * @brief What to do if the snake collides with itself
     * 
     */
    void handleCollisionWithSelf() noexcept;

    /**
     * @brief Move the snake within the game world
     * 
     */
    void move() noexcept;

    /**
     * @brief Reposition the snake within the grid whenever it moves beyond the grid borders
     * 
     */
    void fitSnakeInGrid() noexcept;

    /**
     * @brief Get the position of the head
     * 
     */
    sf::Vector2i const& getHead() const& noexcept;

private:
    std::vector<sf::Vector2i> m_body;
    sf::RectangleShape m_shape { { BlockSize, BlockSize } };
    Direction m_direction = Direction::None;

    /**
     * @brief Set the direction in which the snake is moving
     * 
     * @param direction The new direction
     */
    void setDirection(Direction const& direction) noexcept;

    /**
     * @brief Trim the snake
     * 
     */
    void cut(std::ptrdiff_t const range) noexcept;
};

#endif