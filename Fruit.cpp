#include "Fruit.hpp"

Fruit::Fruit(int x, int y) noexcept : m_position(x, y), m_shape(8)
{
    m_shape.setFillColor(sf::Color::Green);
}

