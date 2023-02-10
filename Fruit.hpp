#ifndef FRUIT_HPP
#define FRUIT_HPP

#include <SFML/System/Vector2.hpp>

class Fruit
{
public:
    /**
     * @brief Construct a new Fruit object
     * 
     * @param x The fruit's position along the x-axis
     * @param y The fruit's position along the y-axis
     */
    Fruit(int x, int y) noexcept;

private:
    sf::Vector2i m_position {};
};

#endif