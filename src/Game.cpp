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
    m_snake.fitSnakeInGrid();
}