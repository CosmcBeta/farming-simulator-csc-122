#include "spinach.hpp"

Spinach::Spinach()
:Plot('j', 2, 3)
{}

void Spinach::update()
{
    dayCounter_ += 1;
    if (dayCounter_ == 1)
    {
        symbol_ = 'J';
        canHarvest_ = true;
    }
}
