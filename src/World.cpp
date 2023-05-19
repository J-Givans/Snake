#include "World.hpp"
#include "Common.hpp"
#include "Snake.hpp"
#include <SFML/Window/Keyboard.hpp>

namespace snake
{
    World::World(sf::Vector2u const& winsize) : m_borders(winsize), m_fruit(winsize), m_winsize(winsize)
    {
    }

    void World::render(sf::RenderWindow& window) &
    {
        m_fruit.render(window);
        m_borders.render(window);
    }

    void World::respawnFruit() &
    {
        m_fruit.respawn();
    }

    std::array<sf::Vector2f, 4> World::getBorders() const& noexcept
    {
        return m_borders.getBorderPositions();
    }

    sf::Vector2i World::getFruitPosition() const&
    {
        return m_fruit.getPosition();
    }
}