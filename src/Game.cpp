#include "Game.hpp"

namespace snake
{
    Game::Game(sf::VideoMode mode, std::string title)
    :   m_window(std::move(mode), std::move(title))
    {
    }
}