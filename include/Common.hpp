#ifndef COMMON_HPP
#define COMMON_HPP

#include <random>

namespace snake
{
    inline constexpr int BlockSize { 16 };
    inline std::random_device rd;
    inline std::mt19937 generator(rd());
}

#endif