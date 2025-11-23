#include "lettuce.hpp"

Lettuce::Lettuce()
:Plot(TILLED_SOIL_SYMBOL, 2, 2)
{}

void Lettuce::update()
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
        symbol_ = 'l'; // will add this to some sort of dictionary at some point to allow for easier lookup
    }
    else
    {
        symbol_ = 'L'; // same with this one, but this is be the same dictionary but set to uppercase via std functions like toupper
        canHarvest_ = true;
    }
}
