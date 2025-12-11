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
  edgeDistribution_(1, 4), bunny_(nullptr)
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
	else if (bunny_ && bunny_->getRow() == row && bunny_->getColumn() == column)
	{
		return bunny_->getSymbol();
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
	// update plants
	dayCounter_ += 1;
	for (auto& row : plots_)
	{
		for (auto& plot : row)
		{
			plot->update();
		}
	}

	// bunny flag
	if (!enableBunnies_) return;

	// if a bunny exists
	if (bunny_)
	{
		// find if its scared
		const int dr[4] = {-1, 1, 0, 0};
		const int dc[4] = {0, 0, -1, 1};
		for (int i = 0; i < 4; i++)
		{
			if (player_->getRow() == bunny_->getRow() + dr[i] &&
				player_->getColumn() == bunny_->getColumn() + dc[i])
			{
				bunny_->scared(dr[i], dc[i]);
			}
		}

		// make current spot soil
		Soil* soil = new Soil();
		plots_.at(bunny_->getRow()).at(bunny_->getColumn()) = soil;

		bunny_->move();

		// if off screen remove bunny
		if (bunny_->getRow() < 0 || bunny_->getRow() >= rows_ || bunny_->getColumn() < 0 ||
			bunny_->getColumn() >= columns_)
		{
			bunny_ = nullptr;
		}
	}
	else
	{
		int bunnyRandomNumber = bunnyChanceDistribution_(generator_); // 1 in 20 (5%)
		if (bunnyRandomNumber == 1)
		{
			int edge = edgeDistribution_(generator_); // 1 in 4 (which edge to put it on)

			switch (edge)
			{
			case 1:
			{
				int randRow = rowDistribution_(generator_);
				if (player_->getRow() == randRow && player_->getColumn() == 0) return;
				bunny_ = new Bunny(randRow, 0);
				break;
			}
			case 2:
			{
				int randRow = rowDistribution_(generator_);
				if (player_->getRow() == randRow && player_->getColumn() == columns_ - 1) return;
				bunny_ = new Bunny(randRow, columns_ - 1);
				break;
			}
			case 3:
			{
				int randCol = columnDistribution_(generator_);
				if (player_->getRow() == 0 && player_->getColumn() == randCol) return;
				bunny_ = new Bunny(0, randCol);
				break;
			}
			case 4:
			{
				int randCol = columnDistribution_(generator_);
				if (player_->getRow() == rows_ - 1 && player_->getColumn() == randCol) return;
				bunny_ = new Bunny(rows_ - 1, randCol);
				break;
			}
			default: break;
			}
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

int Farm::getBunnyRow() const
{
	if (bunny_) return bunny_->getRow();
	else return -1;
}

int Farm::getBunnyCol() const
{
	if (bunny_) return bunny_->getColumn();
	else return -1;
}
