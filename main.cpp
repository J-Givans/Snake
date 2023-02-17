#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "Common.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(Dimensions.width, Dimensions.height), "Snake");
    
    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.display();
    }

    return EXIT_SUCCESS;
}