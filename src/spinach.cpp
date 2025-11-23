#include "spinach.hpp"

Spinach::Spinach()
:Plot(TILLED_SOIL_SYMBOL, 2, 3)
{}

void Spinach::update()
{
    age_ += 1;
    if (hasBeenWatered_)
    {
        age_ += 1;
        hasBeenWatered_ = false;
    }

    if (age_ < daysToSprout_)
    {
        symbol_ = TILLED_SOIL_SYMBOL;
    }
    else if (age_ < daysToSprout_ + daysToHarvest_)
    {
        symbol_ = 'j'; // will add this to some sort of dictionary at some point to allow for easier lookup
    }
    else
    {
        symbol_ = 'J'; // same with this one, but this is be the same dictionary but set to uppercase via std functions like toupper
        canHarvest_ = true;
    }
}
