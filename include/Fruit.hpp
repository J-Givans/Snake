#ifndef FRUIT_HPP
#define FRUIT_HPP

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Common.hpp"

#include <random>

class Fruit
{
public:
    /**
     * @brief Default constructor
     * 
     */
    Fruit() noexcept;

    /**
     * @brief Get the position of the fruit
     * 
     * @return sf::Vector2i const& The position of the fruit as a const lvalue reference
     */
    sf::Vector2f const& getPosition() const& noexcept;
    
    /**
     * @brief Get the shape representing the fruit
     * 
     * @return sf::CircleShape const& The shape as a const lvalue reference
     */
    sf::CircleShape const& get() const& noexcept;
    
    /**
     * @brief Get the shape representing the fruit
     * 
     * @return sf::CircleShape The shape as an rvalue reference
     */
    sf::CircleShape get() && noexcept;

    /**
     * @brief Reposition the fruit elsewhere in the window
     * 
     */
    void respawn() noexcept;

private:
    sf::CircleShape m_shape { static_cast<float>(BlockSize) / 2 };

    static inline std::random_device rd;
    static inline std::mt19937 generator = std::mt19937(rd());

    /**
     * @brief Draw the fruit to the render window
     * 
     * @param window Where the fruit is rendered to
     * @param fruit The fruit to be rendered
     */
    friend void drawFruit(sf::RenderWindow& window, Fruit const& fruit);
};

#endif