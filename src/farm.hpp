#pragma once

#include "plot.hpp"
#include "player.hpp"

#include <vector>

class Farm
{
public:
    Farm(int rows, int columns, Player* player);
    int getNumberOfRows() const;
    int getNumberOfColumns() const;
    char getSymbol(int row, int column) const;
    void plant(int row, int column, Plot* plot);

private:
    int rows_;
    int columns_;
    std::vector<std::vector<Plot*>> plots;
    Player* player_;
};
