#include "Snake.hpp"
#include "Common.hpp"

namespace snake::snake
{
    Snake::Snake()
    {
        shape.setFillColor(sf::Color::Green);
    }

    void Snake::render(sf::RenderWindow& window)
    {
        for (auto const& pos : body) {
            shape.setPosition(sf::Vector2f(pos * BlockSize));
            window.draw(shape);
        }
    }

    void Snake::move()
    {
        for (std::size_t i = body.size() - 1; i > 0; --i) {
            body[i] = body[i - 1];
        }

        if (auto& head = body.front(); direction == Direction::Up) {
            --head.y;
        }
        else if (direction == Direction::Down) {
            ++head.y;
        }
        else if (direction == Direction::Left) {
            --head.x;
        }
        else if (direction == Direction::Right) {
            ++head.x;
        }
    }
}