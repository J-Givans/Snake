#ifndef FRUIT_HPP
#define FRUIT_HPP

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>

#include "Common.hpp"

#include <random>

namespace snake::fruit
{
    inline std::random_device rd;
    inline std::mt19937 generator(rd());

    class Fruit
    {
    public:
        sf::Vector2i position;
        sf::CircleShape shape;

        explicit Fruit(sf::Vector2u const& winsize);
    };
}

#endif