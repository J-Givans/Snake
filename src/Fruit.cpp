#include "Fruit.hpp"
#include "Common.hpp"

#include <random>

namespace snake
{
    Fruit::Fruit() : m_position(), m_winsize()
    {
        m_shape.setRadius(static_cast<float>(BlockSize) / 2);
        m_shape.setFillColor(sf::Color::Yellow);
    }

    Fruit::Fruit(sf::Vector2u const& winsize) : Fruit()
    {
        m_winsize = { (winsize.x / BlockSize) - 2, (winsize.y / BlockSize) - 2 };
        respawn();
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
        m_position.x = (generator() % m_winsize.x) + 1;
        m_position.y = (generator() % m_winsize.y) + 1;

        m_shape.setPosition(sf::Vector2f(m_position * BlockSize));
    }
}