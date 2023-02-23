#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "Common.hpp"
#include "Snake.hpp"
#include "Fruit.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

class Window
{
public:
    /**
     * @brief Default constructor
     * 
     */
    Window() noexcept = default;

    /**
     * @brief Is the window open?
     * 
     */
    [[nodiscard]] bool isOpen() const noexcept;

    /**
     * @brief Handle any events that might occur while the window is open
     * 
     */
    void handleEvents() noexcept;

    /**
     * @brief Render the snake and fruit in the window
     * 
     * @param snake 
     * @param fruit 
     */
    void render(Snake& snake, Fruit const& fruit) noexcept;

private:
    sf::RenderWindow m_window { sf::VideoMode(Dimensions.width, Dimensions.height), "Snake" };

    /**
     * @brief Draw the fruit in the window
     * 
     */
    void drawFruit(Fruit const& fruit) noexcept;

    /**
     * @brief Draw the snake in the window
     * 
     */
    void drawSnake(Snake& snake) noexcept;
};


#endif