#pragma once

#include "player.hpp"
#include "plot.hpp"

#include <vector>

class Farm
{
public:
	Farm(int rows, int columns, Player* player);
	int getNumberOfRows() const;
	int getNumberOfColumns() const;
	char getSymbol(int row, int column) const;
	void plant(int row, int column, Plot* plot);
	void harvest(int row, int column);
	void updatePlants();
	int getDayCount() const;

	void waterPlant(int row, int column);

private:
	int rows_;
	int columns_;
	std::vector<std::vector<Plot*>> plots_;
	Player* player_;
	int dayCounter_;
};
