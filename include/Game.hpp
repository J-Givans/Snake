#ifndef GAME_HPP
#define GAME_HPP

#include "World.hpp"
#include "Snake.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

namespace snake
{
    class Game
    {
        /// \brief Create a new game instance
        /// \param mode The video mode of the console window
        /// \param title The title of the console window
        Game(sf::VideoMode mode, std::string title);

    private:
        sf::RenderWindow m_window;
        World m_world;
        Snake m_snake;
    };
};

#endif