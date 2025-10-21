#include "farm.hpp"
#include "soil.hpp"

#include <vector>

Farm::Farm(int rows, int columns, Player* player)
:rows_(rows), columns_(columns), player_(player)
{
    for(int i = 0; i < rows; i++)
    {
        std::vector<Plot*> row;
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
    plots.at(row).at(column) = plot;
    delete currentPlot;
}
