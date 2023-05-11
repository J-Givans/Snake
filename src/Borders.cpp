#include "Borders.hpp"
#include "Common.hpp"

namespace snake
{
    Borders::Borders(sf::Vector2u const& winSize)
    {
        for (std::array<sf::RectangleShape, 4>::size_type i = 0; i < m_borders.size(); ++i) {
            m_borders[i].setFillColor(sf::Color(150, 0, 0));

            if ((i + 1) % 2 != 0) {
                m_borders[i].setSize(sf::Vector2f(static_cast<float>(winSize.x), snake::BlockSize));
            }
            else {
                m_borders[i].setSize(sf::Vector2f(snake::BlockSize, static_cast<float>(winSize.y)));
            }

            if (i < 2) {
                m_borders[i].setPosition(0, 0);
            }
            else {
                m_borders[i].setOrigin(m_borders[i].getSize());
                m_borders[i].setPosition(sf::Vector2f(winSize));
            }
        }
    }

    void Borders::render(sf::RenderWindow& window) const
    {
        for (auto const& border : m_borders) {
            window.draw(border);
        }
    }
}