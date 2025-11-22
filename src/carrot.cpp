#include "carrot.hpp"

Carrot::Carrot()
:Plot('v', 1, 1)
{}

void Carrot::update()
{
    dayCounter_ += 1;
    if (dayCounter_ == 1)
    {
        symbol_ = 'V';
        canHarvest_ = true;
    }
}
