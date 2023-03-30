#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/CircleShape.hpp>

#include <cstdlib>
#include <random>
#include <vector>

inline constexpr unsigned int BlockSize = 16;

struct Fruit
{
    sf::Vector2i position;
    sf::CircleShape shape;

    Fruit()
    {
        auto const r = BlockSize / 2;
        shape.setRadius(static_cast<float>(r));
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(static_cast<float>(position.x * BlockSize), static_cast<float>(position.y * BlockSize));
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

struct Snake
{
    std::vector<sf::Vector2i> position;
    sf::RectangleShape shape;

    Snake()
    {
        shape.setFillColor(sf::Color::Green);
        shape.setSize(sf::Vector2f(BlockSize, BlockSize));
        
        position.emplace_back(5, 5);
        position.emplace_back(5, 6);
        position.emplace_back(5, 7);
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 400), "Classic Game Of Snake");
    Fruit fruit;
    Snake snake;

    while (window.isOpen()) {
        sf::Event event;
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(fruit.shape);

        for (auto const& s : snake.position) {
            snake.shape.setPosition(static_cast<float>(s.x * BlockSize), static_cast<float>(s.y * BlockSize));
            window.draw(snake.shape);
        }

        window.display();
    }

    return EXIT_SUCCESS;
}