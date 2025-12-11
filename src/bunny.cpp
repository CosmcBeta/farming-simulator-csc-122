#include "bunny.hpp"

#include <chrono>
#include <random>

Bunny::Bunny(int row, int column)
: row_(row), column_(column), symbol_('?'),
  generator_(std::chrono::system_clock::now().time_since_epoch().count()), distribution_(1, 4)
{}

int Bunny::getRow() const
{
	return row_;
}

int Bunny::getColumn() const
{
	return column_;
}

void Bunny::move()
{
	int randomNumber = distribution_(generator_);
	switch (randomNumber)
	{
	case 1 : row_ -= 1; break;
	case 2 : row_ += 1; break;
	case 3 : column_ -= 1; break;
	case 4 : column_ += 1; break;
	default: break;
	}
}

char Bunny::getSymbol() const
{
	return symbol_;
}
