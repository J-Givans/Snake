#include "Game.hpp"
#include "Common.hpp"

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>

namespace snake
{
    Game::Game(sf::VideoMode mode, std::string title)
    :   m_window(std::move(mode), std::move(title))
    {
        m_window.setFramerateLimit(BlockSize);
        m_world = World(m_window.getSize());
    }

    void Game::run() &
    {
        while (m_window.isOpen()) {
            sf::Event event;

            while (m_window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    m_window.close();
                }
            }

            m_snake.tick();

            if (m_snake.getPosition() == m_world.getFruitPosition()) {
                m_snake.grow();
                m_world.respawnFruit();
            }

            m_window.clear();
            m_snake.render(m_window);
            m_world.render(m_window);
            m_window.display();
        }
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