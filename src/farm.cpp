#include "farm.hpp"
#include "bunny.hpp"
#include "plot.hpp"
#include "soil.hpp"

#include <chrono>
#include <random>
#include <vector>

Farm::Farm(int rows, int columns, Player* player, bool bunnies)
: rows_(rows), columns_(columns), player_(player), dayCounter_(1), enableBunnies_(bunnies),
  generator_(std::chrono::system_clock::now().time_since_epoch().count()),
  bunnyChanceDistribution_(1, 20), rowDistribution_(1, rows), columnDistribution_(1, columns),
  edgeDistribution_(1, 4)
{
	for (int i = 0; i < rows; i++)
	{
		std::vector<Plot*> row {};
		for (int j = 0; j < columns; j++)
		{
			Soil* soil = new Soil();
			row.push_back(soil);
		}
		plots_.push_back(row);
	}
}

int Farm::getNumberOfRows() const
{
	return rows_;
}

int Farm::getNumberOfColumns() const
{
	return columns_;
}

char Farm::getSymbol(int row, int column) const
{
	if (player_->getRow() == row && player_->getColumn() == column)
	{
		return player_->getSymbol();
	}
	else
	{
		return plots_.at(row).at(column)->getSymbol();
	}
}

void Farm::plant(int row, int column, Plot* plot)
{
	Plot* currentPlot = plots_.at(row).at(column);

	if (dynamic_cast<Soil*>(currentPlot))
	{
		plots_.at(row).at(column) = plot;
		delete currentPlot;
	}
	else
	{
		delete plot;
	}
}

void Farm::harvest(int row, int column)
{
	Plot* currentPlot = plots_.at(row).at(column);

	if (currentPlot->isHarvestable())
	{
		Soil* soil = new Soil();
		plots_.at(row).at(column) = soil;
		delete currentPlot;
	}
}

void Farm::updatePlants()
{
	dayCounter_ += 1;
	for (auto& row : plots_)
	{
		for (auto& plot : row)
		{
			plot->update();
		}
	}

	if (!enableBunnies_) return;

	int bunnyRandomNumber = bunnyChanceDistribution_(generator_); // 1 in 20 (5%)
	if (bunnyRandomNumber == 1)
	{
		int edge = edgeDistribution_(generator_); // 1 in 4 (which edge to put it on)

		switch (edge)
		{
		case 1:
		{
			int randRow = rowDistribution_(generator_);
			bunnies_.push_back(Bunny(randRow, 0));
			break;
		}
		case 2:
		{
			int randRow = rowDistribution_(generator_);
			bunnies_.push_back(Bunny(randRow, columns_ - 1));
			break;
		}
		case 3:
		{
			int randCol = columnDistribution_(generator_);
			bunnies_.push_back(Bunny(0, randCol));
			break;
		}
		case 4:
		{
			int randCol = columnDistribution_(generator_);
			bunnies_.push_back(Bunny(rows_ - 1, randCol));
			break;
		}
		default: break;
		}
	}
}

int Farm::getDayCount() const
{
	return dayCounter_;
}

void Farm::waterPlant(int row, int column)
{
	plots_.at(row).at(column)->setHasBeenWatered(true);
}
