#ifndef FRUIT_HPP
#define FRUIT_HPP

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

#include "Common.hpp"

namespace snake
{
    class Fruit
    {
    public:
        /// \brief Default constructor
        Fruit();

        /// \brief Default constructor
        /// \param[in] winsize The size of the window in which the Fruit will be rendered
        explicit Fruit(sf::Vector2u const& winsize);

        /// \brief Render the fruit to the window
        /// \param[in] window The window to which the Fruit will be rendered
        void render(sf::RenderWindow& window) const;

        /// \brief Get the position of the fruit
        /// \returns The position of the fruit
        sf::Vector2i const& getPosition() const noexcept;

        /// \brief Set the position of the fruit
        /// \param[in] pos The new position of the fruit
        void setPosition(sf::Vector2i const& pos) noexcept;

        /// \brief Change the position of the fruit in the window
        void respawn();

    private:
        sf::Vector2i m_position;
        sf::CircleShape m_shape;
        sf::Vector2u m_winsize;
    };
}

#endif