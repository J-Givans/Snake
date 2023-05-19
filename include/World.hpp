#ifndef WORLD_HPP
#define WORLD_HPP

#include "Borders.hpp"
#include "Snake.hpp"
#include "Fruit.hpp"

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace snake
{
    /// \brief This class is a facade for the components of the game world.
    /// It contains the classes Fruit and Borders, and the methods required to manipulate them therein
    class World
    {
    public:
        explicit World(sf::Vector2u const& winsize);

        /// \brief Render the game world to the console
        void render(sf::RenderWindow& window) &;

        /// \brief Respawn the fruit
        void respawnFruit() &;

    private:
        Borders m_borders;
        Fruit m_fruit;
        sf::Vector2u m_winsize;
    };
}

#endif