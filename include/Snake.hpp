#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <SFML/System/Vector2.hpp>

#include <vector>
#include <cstddef>

enum class Direction { None, Up, Down, Left, Right };

class Snake
{
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

private:
    std::vector<sf::Vector2i> m_body;
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