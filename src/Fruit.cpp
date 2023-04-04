#include "Fruit.hpp"
#include "Common.hpp"

#include <random>

namespace snake::fruit
{
    Fruit::Fruit(sf::Vector2u const& winsize)
    {
        static std::uniform_int_distribution<> dist(winsize.x, winsize.y);
        position.x = dist(generator) % BlockSize;
        position.y = dist(generator) % BlockSize;

        auto const radius = BlockSize / 2;
        shape.setRadius(radius);
        shape.setFillColor(sf::Color::Yellow);
        shape.setPosition(sf::Vector2f(position * BlockSize));
    }

    void Fruit::render(sf::RenderWindow& window) const
    {
        window.draw(shape);
    }
}