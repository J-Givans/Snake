#ifndef COMMON_HPP
#define COMMON_HPP

/**
 * @brief The size of a single grid in the render window
 * 
 */
inline constexpr unsigned int BlockSize = 16;

struct Vector2
{
    int width { 30 * BlockSize };
    int height { 20 * BlockSize };
};

/**
 * @brief The dimensions of the window to which the game will be rendered
 * 
 */
inline constexpr Vector2 Dimensions;

#endif