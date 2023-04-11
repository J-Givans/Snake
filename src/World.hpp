#ifndef WORLD_HPP
#define WORLD_HPP

#include "Borders.hpp"
#include "Snake.hpp"

#include <SFML/System/Vector2.hpp>

namespace snake::world
{
    class World
    {
    public:
        explicit World(sf::Vector2u const& winsize);

    private:
        Borders m_borders;
        snake::Snake m_snake;

        /// \brief Set the snake direction whenever an arrow-key is pressed
        void setSnakeDirection();
    };
}

#endif