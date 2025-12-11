#include "bunny.hpp"

#include <chrono>
#include <random>

Bunny::Bunny(int row, int column)
: row_(row), column_(column), symbol_('?'), scared_(false),
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
	if (scared_)
	{
		row_ += dr_;
		column_ += dc_;
		scared_ = false;
	}
	else
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
}

char Bunny::getSymbol() const
{
	return symbol_;
}

void Bunny::scared(int dr, int dc)
{
	dr_ = -dr;
	dc_ = -dc;
	scared_ = true;
}
