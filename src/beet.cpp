#include "beet.hpp"

Beet::Beet(): Plot(TILLED_SOIL_SYMBOL, 2, 5) {}

void Beet::update()
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
		symbol_ = 'b';
	}
	else
	{
		symbol_ = 'B';
		canHarvest_ = true;
	}
}
