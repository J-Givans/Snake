#include "Fruit.hpp"
#include "Common.hpp"

#include <random>

namespace snake::fruit
{
    Fruit::Fruit(sf::Vector2u const& winsize) : m_winsize { winsize.x - (2 * BlockSize), winsize.y - (2 * BlockSize) }
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
        m_position.x = (generator() % m_winsize.x) / BlockSize;
        m_position.y = (generator() % m_winsize.y) / BlockSize;

        m_shape.setPosition(sf::Vector2f(m_position * BlockSize));
    }
}