#ifndef GAME_HPP
#define GAME_HPP

#include "World.hpp"
#include "Snake.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

namespace snake
{
    class Game
    {
    private:
        sf::RenderWindow m_window;
        World m_world;
        Snake m_snake;
    };
};

#endif