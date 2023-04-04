#ifndef FRUIT_HPP
#define FRUIT_HPP

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
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
        /// \brief Default constructor
        /// \param[in] winsize The size of the window in which the Fruit will be rendered
        explicit Fruit(sf::Vector2u const& winsize);

        /// \brief Render the fruit to the window
        /// \param[in] window The window to which the Fruit will be rendered
        void render(sf::RenderWindow& window) const;

    private:
        sf::Vector2i position;
        sf::CircleShape shape;
    };
}

#endif