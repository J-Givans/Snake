#ifndef WORLD_HPP
#define WORLD_HPP

#include "Borders.hpp"
#include "Snake.hpp"
#include "Fruit.hpp"

#include <SFML/System/Vector2.hpp>

namespace snake
{
    class World
    {
    public:
        explicit World(sf::Vector2u const& winsize);

        void update(Snake& snake);

    private:
        Borders m_borders;
        Fruit m_fruit;
        sf::Vector2u m_winsize;
    };
}

#endif