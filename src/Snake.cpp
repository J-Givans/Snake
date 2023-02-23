#include "Snake.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <iterator>

Snake::Snake() noexcept
{
    m_body.emplace_back(0, 0);
    m_shape.setFillColor(sf::Color::Green);
}

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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) and m_direction != Direction::Down) {
        setDirection(Direction::Up);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) and m_direction != Direction::Up) {
        setDirection(Direction::Down);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) and m_direction != Direction::Right) {
        setDirection(Direction::Left);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) and m_direction != Direction::Left) {
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

void drawSnake(sf::RenderWindow& window, Snake& snake)
{
    for (auto const& pos : snake.m_body) {
        snake.m_shape.setPosition(pos.x, pos.y);
        window.draw(snake.m_shape);
    }
}

void Snake::move() noexcept
{
    for (auto it = m_body.rbegin(); it != std::prev(m_body.rend()); ++it) {
        *it = *std::next(it);
    }

    if (m_direction == Direction::Up) {
        --m_body.front().y;
    }
    else if (m_direction == Direction::Down) {
        ++m_body.front().y;
    }
    else if (m_direction == Direction::Left) {
        --m_body.front().x;
    }
    else if (m_direction == Direction::Right) {
        ++m_body.front().x;
    }
}