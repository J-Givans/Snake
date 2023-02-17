#include "Snake.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <iterator>

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

void Snake::setDirection() noexcept
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        setDirection(Direction::Up);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        setDirection(Direction::Down);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        setDirection(Direction::Left);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        setDirection(Direction::Right);
    }
}

void Snake::grow() noexcept
{
    auto const& tail = m_body.back();

    if (m_direction == Direction::Up) {
        m_body.emplace_back(tail.x, tail.y + 1);
    }
    else if (m_direction == Direction::Down) {
        m_body.emplace_back(tail.x, tail.y - 1);
    }
    else if (m_direction == Direction::Left) {
        m_body.emplace_back(tail.x + 1, tail.y);
    }
    else if (m_direction == Direction::Right) {
        m_body.emplace_back(tail.x - 1, tail.y);
    }
}

void Snake::handleCollisionWithSelf() noexcept
{
    if (m_body.size() < 5) {
        return;
    }

    for (auto it = std::next(m_body.begin()); it != m_body.end(); ++it) {
        if (*it == m_body.front()) {
            auto rangeToCut = std::distance(it, m_body.end());
            cut(rangeToCut);
        }
        else {
            ++it;
        }
    }
}

void Snake::cut(std::ptrdiff_t const range) noexcept
{
    for (auto i = 0u; i < range; ++i) {
        m_body.pop_back();
    }
}