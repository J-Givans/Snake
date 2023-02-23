#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "Common.hpp"
#include "Snake.hpp"
#include "Fruit.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(Dimensions.width, Dimensions.height), "Snake");
    Snake snake;
    Fruit fruit;
    
    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        snake.setDirection();
        snake.move();

        window.clear();
        drawFruit(window, fruit);
        drawSnake(window, snake);
        window.display();
    }

    return EXIT_SUCCESS;
}