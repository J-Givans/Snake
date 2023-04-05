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
            shape.setPosition(sf::Vector2f(posBlockSize));
            window.draw(shape);
        }
    }
}