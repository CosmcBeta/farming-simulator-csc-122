#include "farm.hpp"
#include "plot.hpp"
#include "soil.hpp"

#include <vector>

Farm::Farm(int rows, int columns, Player* player)
:rows_(rows), columns_(columns), player_(player), dayCounter_(1)
{
    for(int i = 0; i < rows; i++)
    {
        std::vector<Plot*> row {};
        for(int j = 0; j < columns; j++)
        {
            Soil* soil = new Soil();
            row.push_back(soil);
        }
    plots.push_back(row);
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
        return plots.at(row).at(column)->getSymbol();
    }
}

void Farm::plant(int row, int column, Plot* plot)
{
    Plot* currentPlot = plots.at(row).at(column);

    if (dynamic_cast<Soil*>(currentPlot))
    {
        plots.at(row).at(column) = plot;
        delete currentPlot;
    }
    else
    {
        delete plot;
    }
}

void Farm::harvest(int row, int column)
{
    Plot* currentPlot = plots.at(row).at(column);

    if (currentPlot->isHarvestable())
    {
        Soil* soil = new Soil();
        plots.at(row).at(column) = soil;
        delete currentPlot;
    }
}

void Farm::updatePlants()
{
    dayCounter_ += 1;
    for (auto& row : plots)
    {
        for (auto& plot : row)
        {
            plot->update();
        }
    }
}

int Farm::getDayCount() const
{
    return dayCounter_;
}
