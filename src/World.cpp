#include "World.hpp"
#include "Snake.hpp"
#include <SFML/Window/Keyboard.hpp>

namespace snake::world
{
    World::World(sf::Vector2u const& winsize) : m_borders(winsize), m_fruit(winsize)
    {
    }
}