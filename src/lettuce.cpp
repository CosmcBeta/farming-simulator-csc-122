#include "lettuce.hpp"

Lettuce::Lettuce(): Plot(TILLED_SOIL_SYMBOL, 2, 2) {}

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
		symbol_ = 'l';
	}
	else
	{
		symbol_ = 'L';
		canHarvest_ = true;
	}
}
