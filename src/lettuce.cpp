#include "lettuce.hpp"

Lettuce::Lettuce()
:Plot('l', 2, 2)
{}

void Lettuce::update()
{
    dayCounter_ += 1;
    if (dayCounter_ == 1)
    {
        symbol_ = 'L';
        canHarvest_ = true;
    }
}
