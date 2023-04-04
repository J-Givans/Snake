#include "Fruit.hpp"
#include "Common.hpp"

#include <random>

namespace snake::fruit
{
    Fruit::Fruit(sf::Vector2u const& winsize) : m_winsize { winsize }
    {
        respawn();
        m_shape.setFillColor(sf::Color::Yellow);
    }

    void Fruit::render(sf::RenderWindow& window) const
    {
        window.draw(m_shape);
    }

    sf::Vector2i const& Fruit::getPosition() const noexcept
    {
        return m_position;
    }

    void Fruit::respawn()
    {
        static std::uniform_int_distribution<> dist(m_winsize.x % BlockSize, m_winsize.y % BlockSize);
        m_position.x = dist(generator);
        m_position.y = dist(generator);

        m_shape.setPosition(sf::Vector2f(m_position * BlockSize));
    }
}