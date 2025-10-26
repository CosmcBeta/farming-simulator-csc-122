#pragma once

#include "farm_printer.hpp"
#include "player.hpp"
#include "farm.hpp"

class Game
{
public:
    Game();
    ~Game() = default;
    void displayKey();
    void run();
private:
    Player player_;
    Farm farm_;
    FarmPrinter printer_;
};
