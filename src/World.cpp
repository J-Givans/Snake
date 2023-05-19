#include "World.hpp"
#include "Common.hpp"
#include "Snake.hpp"
#include <SFML/Window/Keyboard.hpp>

namespace snake
{
    World::World(sf::Vector2u const& winsize) : m_borders(winsize), m_fruit(winsize), m_winsize(winsize)
    {
    }
}