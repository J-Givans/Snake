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

void Snake::grow() noexcept
{
    auto const& tail = m_body.back();

    if (m_direction == Direction::Up) {
        m_body.emplace_back(tail.position.x, tail.position.y + 1);
    }
    else if (m_direction == Direction::Down) {
        m_body.emplace_back(tail.position.x, tail.position.y - 1);
    }
    else if (m_direction == Direction::Left) {
        m_body.emplace_back(tail.position.x + 1, tail.position.y);
    }
    else if (m_direction == Direction::Right) {
        m_body.emplace_back(tail.position.x - 1, tail.position.y);
    }
}