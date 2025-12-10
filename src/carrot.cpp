#include "carrot.hpp"

Carrot::Carrot(): Plot(TILLED_SOIL_SYMBOL, 1, 1) {}

void Carrot::update()
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
		symbol_ = 'v';
	}
	else
	{
		symbol_ = 'V';
		canHarvest_ = true;
	}
}
