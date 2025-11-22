#include "spinach.hpp"

Spinach::Spinach()
:Plot('h', 2, 3)
{}

void Spinach::update()
{
    dayCounter_ += 1;
    if (dayCounter_ == 1)
    {
        symbol_ = 'H';
        canHarvest_ = true;
    }
}
