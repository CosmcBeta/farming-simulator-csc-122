#include "plot.hpp"

Plot::~Plot()
{}

Plot::Plot(char symbol)
:symbol_(symbol)
{}

char Plot::getSymbol() const
{
    return symbol_;
}
