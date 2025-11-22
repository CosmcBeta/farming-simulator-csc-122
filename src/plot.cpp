#include "plot.hpp"

Plot::~Plot()
{}

Plot::Plot(char symbol, int daysToSprout, int daysToHarvest)
:symbol_(symbol), dayCounter_(0), canHarvest_(false),
daysToHarvest_(daysToHarvest), daysToSprout_(daysToSprout),
hasBeenWatered_(false)
{}

char Plot::getSymbol() const
{
    return symbol_;
}

void Plot::update()
{}

bool Plot::isHarvestable() const
{
    return canHarvest_;
}

bool Plot::hasBeenWatered() const
{
    return hasBeenWatered_;
}

void Plot::setHasBeenWatered(bool watered)
{
    hasBeenWatered_ = watered;
}
