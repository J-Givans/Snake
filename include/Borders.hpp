#ifndef BORDERS_HPP
#define BORDERS_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <SFML/System/Vector2.hpp>
#include <array>

namespace snake
{
    class Borders
    {
    public:
        /// Default constructor
        Borders();

        /// \brief Constructor
        /// \param[in] winsize The size of the window to which the borders will be rendered
        explicit Borders(sf::Vector2u const& winsize);

        /// \brief Render the borders to the screen
        /// \param[in] The window in which the borders will be rendered
        void render(sf::RenderWindow& window) const;

    private:
        std::array<sf::RectangleShape, 4> m_borders;
    };
}

#endif