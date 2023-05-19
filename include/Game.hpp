#ifndef GAME_HPP
#define GAME_HPP

#include "World.hpp"
#include "Snake.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

namespace snake
{
    class Game
    {
    public:
        /// \brief Create a new game instance
        /// \param mode The video mode of the console window
        /// \param title The title of the console window
        Game(sf::VideoMode mode, std::string title);

        /// \brief Main game loop
        void run() &;

    private:
        sf::RenderWindow m_window;
        World m_world;
        Snake m_snake;

        /// \brief Set the direction of the snake in response to a valid key press
        void setSnakeDirection() &;
    };
};

#endif