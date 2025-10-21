#include "ansi_clear.hpp"

#include <iostream>

void ansi_clear()
{
    std::cout << "\033[2J\033[H";
}
