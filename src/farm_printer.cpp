#include "farm_printer.hpp"
#include "farm.hpp"

#include <string>

FarmPrinter::FarmPrinter(Farm* farm): farm_(farm) {}

std::string FarmPrinter::prettyPrint()
{
	std::string output {""};
	for (int i = 0; i < farm_->getNumberOfRows(); i++)
	{
		for (int j = 0; j < farm_->getNumberOfColumns(); j++)
		{
			output += farm_->getSymbol(i, j);
			output += " ";
		}
		output += "\n";
	}
	return output;
}

std::string FarmPrinter::printLegend()
{
	std::string output {""};
	output += "Controls\n";
	output += "[W/A/S/D] Move\n";
	output += "[C] Plant Carrot\n";
	output += "[L] Plant Lettuce\n";
	output += "[J] Plant Spinach\n";
	output += "[B] Plant Beet\n";
	output += "[N] Plant Brussel Sprout\n";
	output += "[R] Water Plant\n";
	output += "[H] Harvest\n";
	output += "[E] End Day\n";
	output += "[Q] Quit Game\n";

	output += "\nInformation\n";
	output += "Day: ";
	output += std::to_string(farm_->getDayCount());

	return output;
}
