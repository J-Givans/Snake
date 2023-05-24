#include "Borders.hpp"
#include "Common.hpp"

namespace snake
{
    Borders::Borders()
    {
        for (auto& border : m_borders) {
            border.setFillColor(sf::Color(150, 0, 0));
        }
    }

    Borders::Borders(sf::Vector2u const& winSize) : Borders()
    {
        for (std::array<sf::RectangleShape, 4>::size_type i = 0; i < m_borders.size(); ++i) {
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

    std::array<sf::Vector2f, 4> Borders::getBorderPositions() const& noexcept
    {
        return std::array<sf::Vector2f, 4> {
            m_borders[0].getPosition(),
            m_borders[1].getPosition(),
            m_borders[2].getPosition(),
            m_borders[3].getPosition()
        };
    }

    void Borders::render(sf::RenderWindow& window) const
    {
        for (auto const& border : m_borders) {
            window.draw(border);
        }
    }
}