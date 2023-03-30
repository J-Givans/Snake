#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/CircleShape.hpp>

#include <cstdlib>
#include <random>

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

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 400), "Classic Game Of Snake");
    Fruit fruit;

    while (window.isOpen()) {
        sf::Event event;
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(fruit.shape);
        window.display();
    }

    return EXIT_SUCCESS;
}