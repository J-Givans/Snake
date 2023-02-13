#include "Fruit.hpp"

Fruit::Fruit(float x, float y) noexcept
{
    m_shape.setFillColor(sf::Color::Green);
    m_shape.setPosition(x, y);
}

sf::Vector2f const& Fruit::getPosition() const& noexcept
{
    return m_shape.getPosition();
}

sf::CircleShape const& Fruit::getShape() const& noexcept
{
    return m_shape;
}

sf::CircleShape Fruit::getShape() && noexcept
{
    return std::move(m_shape);
}