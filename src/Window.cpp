#include "Window.hpp"

[[nodiscard]] bool Window::isOpen() const noexcept
{
    return m_window.isOpen();
}

void Window::handleEvents() noexcept
{
    sf::Event event;

    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_window.close();
        }
    }
}

void Window::drawFruit(Fruit const& fruit) noexcept
{
    m_window.draw(fruit.m_shape);
}

void Window::drawSnake(Snake& snake) noexcept
{
    for (auto const& pos : snake.m_body) {
        snake.m_shape.setPosition(static_cast<float>(pos.x), static_cast<float>(pos.y));
        m_window.draw(snake.m_shape);
    }
}

void Window::render(Snake& snake, Fruit const& fruit) noexcept
{
    m_window.clear();
    drawSnake(snake);
    drawFruit(fruit);
    m_window.display();
}