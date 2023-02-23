#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Sleep.hpp>
#include <SFML/System/Time.hpp>

#include "Common.hpp"
#include "Snake.hpp"
#include "Fruit.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(Dimensions.width, Dimensions.height), "Snake");
    Snake snake;
    Fruit fruit;
    
    sf::Clock clock;
    sf::Time elapsedTime;

    static constexpr float timeStep = 1.0f / (BlockSize * 10); 

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (elapsedTime >= sf::seconds(timeStep)) {
            snake.setDirection();
            snake.move();
            snake.fitSnakeInGrid();
            elapsedTime -= sf::seconds(timeStep);
        }

        window.clear();
        drawFruit(window, fruit);
        drawSnake(window, snake);
        window.display();

        elapsedTime += clock.restart();
    }

    return EXIT_SUCCESS;
}