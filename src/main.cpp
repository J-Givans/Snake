#include <SFML/Window/VideoMode.hpp>

#include "Game.hpp"

using snake::Game;

int main()
{
    Game game(sf::VideoMode(600, 400), "Classic Game Of Snake");
    game.run();
    
    return EXIT_SUCCESS;
}