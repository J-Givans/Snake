#ifndef FRUIT_HPP
#define FRUIT_HPP

#include <SFML/Graphics/CircleShape.hpp>
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

    /**
     * @brief Get the position of the fruit
     * 
     * @return sf::Vector2i const& The position of the fruit as a const lvalue reference
     */
    sf::Vector2i const& getPosition() const& noexcept;
    
    /**
     * @brief Get the position of the fruit
     * 
     * @return sf::Vector2i The position of the fruit as an rvalue
     */
    sf::Vector2i getPosition() && noexcept;

    /**
     * @brief Get the shape representing the fruit
     * 
     * @return sf::CircleShape const& The shape as a const lvalue reference
     */
    sf::CircleShape const& getShape() const& noexcept;
    
    /**
     * @brief Get the shape representing the fruit
     * 
     * @return sf::CircleShape The shape as an rvalue reference
     */
    sf::CircleShape getShape() && noexcept;

private:
    sf::Vector2i m_position {};
    sf::CircleShape m_shape {};
};

#endif