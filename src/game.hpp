#pragma once

#include "farm.hpp"
#include "farm_printer.hpp"
#include "player.hpp"

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
