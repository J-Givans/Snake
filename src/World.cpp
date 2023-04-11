#include "World.hpp"
#include "Snake.hpp"
#include <SFML/Window/Keyboard.hpp>

namespace snake::world
{
    World::World(sf::Vector2u const& winsize) : m_borders(winsize)
    {
    }

    void World::setSnakeDirection()
    {
        using snake::Direction;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) and m_snake.getDirection() != Direction::Down) {
            m_snake.setDirection(Direction::Up);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) and m_snake.getDirection() != Direction::Up) {
            m_snake.setDirection(Direction::Down);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) and m_snake.getDirection() != Direction::Right) {
            m_snake.setDirection(Direction::Left);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) and m_snake.getDirection() != Direction::Left) {
            m_snake.setDirection(Direction::Right);
        }
    }
}