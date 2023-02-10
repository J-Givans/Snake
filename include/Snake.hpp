#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <SFML/System/Vector2.hpp>

#include <vector>

enum class Direction { None, Up, Down, Left, Right };

struct Snakelet
{
    sf::Vector2f position {};
};

class Snake
{
public:
    Snake() noexcept = default;

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

private:
    std::vector<Snakelet> m_body {};
    Direction m_direction = Direction::None;
};

#endif