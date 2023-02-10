#include "Fruit.hpp"

Fruit::Fruit(float x, float y) noexcept : m_position(x, y), m_shape(8)
{
    m_shape.setFillColor(sf::Color::Green);
    m_shape.setPosition(m_position);
}

sf::Vector2f const& Fruit::getPosition() const& noexcept
{
    return m_position;
}

sf::Vector2f Fruit::getPosition() && noexcept
{
    return std::move(m_position);
}

sf::CircleShape const& Fruit::getShape() const& noexcept
{
    return m_shape;
}

sf::CircleShape Fruit::getShape() && noexcept
{
    return std::move(m_shape);
}