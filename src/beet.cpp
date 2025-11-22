#include "beet.hpp"

Beet::Beet()
:Plot('b', 2, 5)
{}

void Beet::update()
{
    dayCounter_ += 1;
    if (dayCounter_ == 1)
    {
        symbol_ = 'B';
        canHarvest_ = true;
    }
}
