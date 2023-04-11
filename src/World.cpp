#include "World.hpp"
#include "Common.hpp"
#include "Snake.hpp"
#include <SFML/Window/Keyboard.hpp>

namespace snake::world
{
    World::World(sf::Vector2u const& winsize) : m_borders(winsize), m_fruit(winsize), m_winsize(winsize)
    {
    }

    void World::update(snake::Snake& snake)
    {
        if (snake.getPosition() == m_fruit.getPosition()) {
            snake.grow();
            m_fruit.respawn();
        }

        {
            auto const& pos = snake.getPosition();
            auto const& ws = sf::Vector2i(m_winsize) / BlockSize;

            if (pos.x == 0 or pos.y == 0 or pos.x >= ws.x - 1 or pos.x >= ws.y - 1) {
                snake.reset();
            }
        }
    }
}