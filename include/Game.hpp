#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include "Common.hpp"
#include "Snake.hpp"
#include "Fruit.hpp"
#include "Window.hpp"

class Game
{
public:
    /**
     * @brief Default constructor
     * 
     */
    Game() noexcept = default;

    /**
     * @brief Main game logic
     * 
     */
    void run();

private:
    Window m_window;
    Fruit m_fruit;
    Snake m_snake;
    sf::Clock m_clock;
    sf::Time m_elapsedTime;

    /**
     * @brief Handles any updates to the game that happen within a single clock cycle
     * 
     */
    void tick() noexcept;
};

#endif