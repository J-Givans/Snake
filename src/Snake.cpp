#include "Snake.hpp"
#include "Common.hpp"

namespace snake
{
    Snake::Snake()
    {
        shape.setFillColor(sf::Color::Green);
    }

    void Snake::render(sf::RenderWindow& window)
    {
        for (auto const& pos : body) {
            shape.setPosition(sf::Vector2f(pos * BlockSize));
            window.draw(shape);
        }
    }

    void Snake::move() noexcept
    {
        for (std::size_t i = body.size() - 1; i > 0; --i) {
            body[i] = body[i - 1];
        }

        if (auto& head = body.front(); direction == Direction::Up) {
            --head.y;
        }
        else if (direction == Direction::Down) {
            ++head.y;
        }
        else if (direction == Direction::Left) {
            --head.x;
        }
        else if (direction == Direction::Right) {
            ++head.x;
        }
    }

    void Snake::grow()
    {
        if (body.empty()) {
            return;
        }

        if (auto& tail = body.back(); body.size() > 1) {
            auto const& preTail = body[body.size() - 2];

            if (tail.x == preTail.x) {
                if (tail.y > preTail.y) {
                    body.emplace_back(tail.x, tail.y + 1);
                }
                else {
                    body.emplace_back(tail.x, tail.y - 1);
                }
            }
            else if (tail.y == preTail.y) {
                if (tail.x > preTail.x) {
                    body.emplace_back(tail.x + 1, tail.y);
                }
                else {
                    body.emplace_back(tail.x - 1, tail.y);
                }
            }
            else {
                if (direction == Direction::Up) {
                    body.emplace_back(tail.x, tail.y + 1);
                }
                else if (direction == Direction::Down) {
                    body.emplace_back(tail.x, tail.y - 1);
                }
                else if (direction == Direction::Left) {
                    body.emplace_back(tail.x - 1, tail.y);
                }
                else if (direction == Direction::Right) {
                    body.emplace_back(tail.x + 1, tail.y);
                }
            }
        }
    }

    void Snake::setDirection(Direction d) noexcept
    {
        direction = d;
    }

    Direction Snake::getDirection() const noexcept
    {
        return direction;
    }

    void Snake::checkCollision()
    {
        if (body.size() < 5) {
            return;
        }

        for (auto it = std::next(body.cbegin()); it != body.cend(); ++it) {
            if (*it == body.front()) {
                auto const segments = std::distance(it, body.cend());
                shrink(segments);
                break;
            }
        }
    }

    void Snake::shrink(std::ptrdiff_t segments) noexcept
    {
        while (segments > 0) {
            body.pop_back();
            segments -= 1;
        }
    }

    sf::Vector2i const& Snake::getPosition() const noexcept
    {
        return body.front();
    }

    void Snake::reset()
    {
        body.clear();

        body.emplace_back(5, 5);
        body.emplace_back(5, 6);
        body.emplace_back(5, 7);

        direction = Direction::None;
    }

    void Snake::tick()
    {
        if (body.empty() or direction == Direction::None) {
            return;
        }

        move();
        checkCollision();
    }
}