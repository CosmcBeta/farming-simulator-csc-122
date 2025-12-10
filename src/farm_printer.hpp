#pragma once

#include "farm.hpp"

class FarmPrinter
{
public:
	FarmPrinter(Farm* farm);
	std::string prettyPrint();
	std::string printLegend();

private:
	Farm* farm_;
};
