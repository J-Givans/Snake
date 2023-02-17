#include "Fruit.hpp"
#include "Common.hpp"

Fruit::Fruit() noexcept
{
    m_shape.setPosition(static_cast<float>(Dimensions.width) / 2, static_cast<float>(Dimensions.height) / 2);
    m_shape.setFillColor(sf::Color::Red);
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