#include "plot.hpp"

Plot::~Plot()
{}

Plot::Plot(char symbol)
:symbol_(symbol), dayCounter_(0), canHarvest_(false)
{}

char Plot::getSymbol() const
{
    return symbol_;
}

void Plot::update()
{}

bool Plot::isHarvestable()
{
    return canHarvest_;
}
