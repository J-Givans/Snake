#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <SFML/System/Vector2.hpp>

#include <vector>

enum class Direction { None, Up, Down, Left, Right };

struct Snakelet
{
    sf::Vector2f position {};
    Direction direction = Direction::None;
};

class Snake
{
public:
    Snake() noexcept = default;

private:
    std::vector<Snakelet> m_body {};
};

#endif