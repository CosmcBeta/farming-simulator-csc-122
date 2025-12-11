#pragma once

#include <random>

class Bunny
{
public:
	Bunny(int row, int column);
	int getRow() const;
	int getColumn() const;
	void move();
	char getSymbol() const;
	void scared(int dr, int dc);

private:
	int row_;
	int column_;
	char symbol_;
	std::mt19937 generator_;
	std::uniform_int_distribution<int> distribution_;

	bool scared_;
	int dr_;
	int dc_;
};
