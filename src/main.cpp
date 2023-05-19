#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

#include <cstddef>
#include <cstdlib>
#include <vector>

#include "Common.hpp"
#include "World.hpp"

enum class Direction { None, Up, Down, Left, Right };

struct Snake
{
    std::vector<sf::Vector2i> position;
    sf::RectangleShape shape;
    Direction direction { Direction::None };

    Snake()
    {
        init();
    }

    void move() &
    {
        setDirection();

        for (std::size_t i = position.size() - 1; i > 0; --i) {
            position[i].x = position[i - 1].x;
            position[i].y = position[i - 1].y;
        }

        if (auto& head = position.front(); direction == Direction::Up) {
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

    void reset() &
    {
        position.clear();

        direction = Direction::None;
        init();
    }

    void grow() &
    {
        if (auto const& tail = position.back(); direction == Direction::Up) {
            position.emplace_back(tail.x, tail.y + 1);
        }
        else if (direction == Direction::Down) {
            position.emplace_back(tail.x, tail.y - 1);
        }
        else if (direction == Direction::Left) {
            position.emplace_back(tail.x - 1, tail.y);
        }
        else if (direction == Direction::Right) {
            position.emplace_back(tail.x + 1, tail.y);
        }
    }

    void handleSelfCollision() &
    {
        if (position.size() < 5) {
            return;
        }

        for (auto it = std::next(position.begin()); it != position.end(); ++it) {
            if (*it == position.front()) {
                auto const shrinkPoint = std::distance(it, position.end());
                shrink(shrinkPoint);
                break;
            }
        }
    }

    void render(sf::RenderWindow& window) &
    {
        for (auto const& s : position) {
            shape.setPosition(static_cast<float>(s.x * snake::BlockSize), static_cast<float>(s.y * snake::BlockSize));
            window.draw(shape);
        }
    }

private:
    void setDirection() & noexcept
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) and direction != Direction::Down) {
            direction = Direction::Up;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) and direction != Direction::Up) {
            direction = Direction::Down;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) and direction != Direction::Right) {
            direction = Direction::Left;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) and direction != Direction::Right) {
            direction = Direction::Right;
        }
    }

    void init() &
    {
        shape.setFillColor(sf::Color::Green);
        shape.setSize(sf::Vector2f(snake::BlockSize, snake::BlockSize));

        position.emplace_back(5, 5);
        position.emplace_back(6, 5);
        position.emplace_back(7, 5);
    }

    void shrink(std::ptrdiff_t point)
    {
        for (auto i = 0; i < point; ++i) {
            position.pop_back();
        }
    }
};

enum class Status { Alive, Dead };

struct PlayerData
{
    int score {};
    Status status { Status::Dead };
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 400), "Classic Game Of Snake");
    snake::World world(window.getSize());
    Snake snake;
    PlayerData data { .score = 10, .status = Status::Alive };

    window.setFramerateLimit(snake::BlockSize);

    while (window.isOpen()) {
        sf::Event event;
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        snake.move();

        if (snake.position.front() == world.getFruitPosition()) {
            snake.grow();
            data.score += 10;
            world.respawnFruit();
        }

        snake.handleSelfCollision();

        window.clear();
        
        snake.render(window);
        world.render(window);

        window.display();
    }

    return EXIT_SUCCESS;
}