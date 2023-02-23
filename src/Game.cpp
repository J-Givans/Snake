#include "Game.hpp"

void Game::run()
{
    static constexpr float timeStep = 1.0 / (BlockSize * BlockSize);

    while (m_window.isOpen()) {
        m_window.handleEvents();
        m_snake.setDirection();
        
        if (m_elapsedTime >= sf::seconds(timeStep)) {
            tick();
            m_elapsedTime -= sf::seconds(timeStep);
        }

        m_window.render(m_snake, m_fruit);
        m_elapsedTime += m_clock.restart();
    }
}

void Game::tick() noexcept
{
    m_snake.move();

    // If the snake eats the fruit, respawn the fruit elsewhere in the grid, and grow the snake
    if (m_snake.getHead() == m_fruit.getPosition()) {
        m_snake.grow();
        m_fruit.respawn();
    }

    // If the snake collides with itself, shrink it
    m_snake.handleCollisionWithSelf();

    m_snake.fitSnakeInGrid();
}