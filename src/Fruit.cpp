#include "Fruit.hpp"
#include "Common.hpp"

#include <random>

namespace snake::fruit
{
    Fruit::Fruit(sf::Vector2u const& winsize) : m_winsize { winsize }
    {
        static std::uniform_int_distribution<> dist(winsize.x % BlockSize, winsize.y % BlockSize);
        m_position.x = dist(generator);
        m_position.y = dist(generator);

        auto const radius = BlockSize / 2;
        m_shape.setRadius(radius);
        m_shape.setFillColor(sf::Color::Yellow);
        m_shape.setPosition(sf::Vector2f(m_position * BlockSize));
    }

    void Fruit::render(sf::RenderWindow& window) const
    {
        window.draw(m_shape);
    }

    sf::Vector2i const& Fruit::getPosition() const noexcept
    {
        return m_position;
    }
}