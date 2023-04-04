#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/CircleShape.hpp>

#include <cstddef>
#include <cstdlib>
#include <random>
#include <vector>
#include <array>

inline constexpr unsigned int BlockSize = 16;

struct Fruit
{
    sf::Vector2i position;
    sf::CircleShape shape;

    Fruit()
    {
        auto const r = BlockSize / 2;
        shape.setRadius(static_cast<float>(r));
        shape.setFillColor(sf::Color::Yellow);
        shape.setPosition(static_cast<float>(position.x * BlockSize), static_cast<float>(position.y * BlockSize));
    }

    void render(sf::RenderWindow& window) const&
    {
        window.draw(shape);
    }
};

void respawn(Fruit& f, sf::Vector2u const& winSize)
{
    static std::random_device rd;
    static std::mt19937 generator(rd());

    f.position.x = generator() % (winSize.x / BlockSize);
    f.position.y = generator() % (winSize.y / BlockSize);

    f.shape.setPosition(static_cast<float>(f.position.x * BlockSize), static_cast<float>(f.position.y * BlockSize));
}

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
        shape.setSize(sf::Vector2f(BlockSize, BlockSize));

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

struct Borders
{
    std::array<sf::RectangleShape, 4> boundary;

    explicit Borders(sf::Vector2u const& winSize)
    {
        for (std::array<sf::RectangleShape, 4>::size_type i = 0; i < boundary.size(); ++i) {
            boundary[i].setFillColor(sf::Color(150, 0, 0));

            if ((i + 1) % 2 != 0) {
                boundary[i].setSize(sf::Vector2f(static_cast<float>(winSize.x), BlockSize));
            }
            else {
                boundary[i].setSize(sf::Vector2f(BlockSize, static_cast<float>(winSize.y)));
            }

            if (i < 2) {
                boundary[i].setPosition(0, 0);
            }
            else {
                boundary[i].setOrigin(boundary[i].getSize());
                boundary[i].setPosition(sf::Vector2f(winSize));
            }
        }
    }

    void render(sf::RenderWindow& window) const
    {
        for (auto const& border : boundary) {
            window.draw(border);
        }
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 400), "Classic Game Of Snake");
    Fruit fruit;
    Snake snake;
    PlayerData data { .score = 10, .status = Status::Alive };
    Borders borders(window.getSize());

    window.setFramerateLimit(BlockSize);

    while (window.isOpen()) {
        sf::Event event;
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        snake.move();

        if (snake.position.front() == fruit.position) {
            snake.grow();
            data.score += 10;
            respawn(fruit, window.getSize());
        }

        snake.handleSelfCollision();

        window.clear();
        fruit.render(window);

        for (auto const& s : snake.position) {
            snake.shape.setPosition(static_cast<float>(s.x * BlockSize), static_cast<float>(s.y * BlockSize));
            window.draw(snake.shape);
        }

        borders.render(window);

        window.display();
    }

    return EXIT_SUCCESS;
}