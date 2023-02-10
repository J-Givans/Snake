#include "Snake.hpp"

Direction const& Snake::getDirection() const& noexcept
{
    return m_body.front().direction;
}

Direction Snake::getDirection() && noexcept
{
    return std::move(m_body.front().direction);
}