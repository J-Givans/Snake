#include "Game.hpp"
#include "Common.hpp"

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>

namespace snake
{
    Game::Game(sf::VideoMode const& mode, std::string const& title)
    :   m_window(mode, title)
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

            setSnakeDirection();
            m_snake.tick();

            if (m_snake.getPosition() == m_world.getFruitPosition()) {
                m_snake.grow();
                m_world.respawnFruit();
            }

            handleSnakeBorderCollision();

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

    void Game::handleSnakeBorderCollision() &
    {
        sf::Vector2i worldSize = sf::Vector2i(m_window.getSize()) / BlockSize;
        auto pos = m_snake.getPosition(); 

        if (pos.x <= 0 or pos.y <= 0 or pos.x >= worldSize.x - 1 or pos.y >= worldSize.y - 1) {
            m_snake.reset();
        }
    }
}