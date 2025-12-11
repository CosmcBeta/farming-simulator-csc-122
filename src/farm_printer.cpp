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
	output += "[W/A/S/D] Move       [C] Plant Carrot    [B] Plant Beet    [L] Plant Lettuce\n";
	output += "[J] Plant Spinach    [N] Plant Brussel Sprout\n";
	output += "[R] Water Plant      [H] Harvest         [E] End Day       [Q] Quit Game\n";

	output += "\nCharacters:\n";
	output += "[@] Player    [?] Bunny    [.] Empty    [~] Seedling\n";
	output +=
		"[v/V] Carrot    [b/B] Beet    [l/L] Lettuce    [j/J] Spinach    [n/N] Brussel Sprout\n";
	output += "(lowercase = baby, uppercase = adult)\n";

	output += "Day: ";
	output += std::to_string(farm_->getDayCount());

	return output;
}
