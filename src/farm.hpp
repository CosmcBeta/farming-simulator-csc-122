#pragma once

#include "bunny.hpp"
#include "player.hpp"
#include "plot.hpp"

#include <random>
#include <vector>

class Farm
{
public:
	Farm(int rows, int columns, Player* player, bool bunnies = true);
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
	bool enableBunnies_;
	std::mt19937 generator_;
	std::uniform_int_distribution<int> bunnyChanceDistribution_;
	std::uniform_int_distribution<int> rowDistribution_;
	std::uniform_int_distribution<int> columnDistribution_;
	std::uniform_int_distribution<int> edgeDistribution_;

	Bunny* bunny_;
};
