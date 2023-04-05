#include "Snake.hpp"
#include "Common.hpp"

namespace snake::snake
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

    void Snake::move()
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
}