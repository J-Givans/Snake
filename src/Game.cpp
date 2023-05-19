#include "Game.hpp"
#include "Common.hpp"

#include <SFML/Window/Keyboard.hpp>

namespace snake
{
    Game::Game(sf::VideoMode mode, std::string title)
    :   m_window(std::move(mode), std::move(title))
    {
        m_window.setFramerateLimit(BlockSize);
    }

    void Game::setSnakeDirection() &
    {
        auto direction = m_snake.getDirection();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) and direction != Direction::Down) {
            m_snake.setDirection(Direction::Up);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) and direction != Direction::Up) {
            m_snake.setDirection(Direction::Down);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) and direction != Direction::Right) {
            m_snake.setDirection(Direction::Left);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) and direction != Direction::Right) {
            m_snake.setDirection(Direction::Right);
        }        
    }
}