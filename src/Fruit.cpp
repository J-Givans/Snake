#include "Fruit.hpp"
#include "Common.hpp"

Fruit::Fruit() noexcept
{
    m_shape.setPosition(static_cast<float>(Dimensions.width) / 2, static_cast<float>(Dimensions.height) / 2);
    m_shape.setFillColor(sf::Color::Red);
}

sf::Vector2i Fruit::getPosition() const& noexcept
{
    auto const& fruitPos = m_shape.getPosition();
    auto pos = sf::Vector2i(static_cast<int>(fruitPos.x), static_cast<int>(fruitPos.y));

    return pos;
}

sf::CircleShape const& Fruit::get() const& noexcept
{
    return m_shape;
}

sf::CircleShape Fruit::get() && noexcept
{
    return std::move(m_shape);
}

void Fruit::respawn() noexcept
{
    auto newPos = m_shape.getPosition();

    newPos.x = Fruit::generator() % Dimensions.height;
    newPos.y = Fruit::generator() % Dimensions.width;

    m_shape.setPosition(newPos);
}