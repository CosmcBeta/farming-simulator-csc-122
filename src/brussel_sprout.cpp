#include "brussel_sprout.hpp"

BrusselSprout::BrusselSprout()
:Plot('n', 5, 10)
{}

void BrusselSprout::update()
{
    dayCounter_ += 1;
    if (dayCounter_ == 1)
    {
        symbol_ = 'N';
        canHarvest_ = true;
    }
}
