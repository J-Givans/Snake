#include "Snake.hpp"

Direction const& Snake::getDirection() const& noexcept
{
    return m_direction;
}

Direction Snake::getDirection() && noexcept
{
    return std::move(m_direction);
}

void Snake::setDirection(Direction const& direction) noexcept
{
    m_direction = direction;
}