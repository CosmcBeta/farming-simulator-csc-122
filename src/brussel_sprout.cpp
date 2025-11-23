#include "brussel_sprout.hpp"

BrusselSprout::BrusselSprout()
:Plot(TILLED_SOIL_SYMBOL, 5, 10)
{}

void BrusselSprout::update()
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
        symbol_ = 'n'; // will add this to some sort of dictionary at some point to allow for easier lookup
    }
    else
    {
        symbol_ = 'N'; // same with this one, but this is be the same dictionary but set to uppercase via std functions like toupper
        canHarvest_ = true;
    }
}
