#include "farm_printer.hpp"
#include "farm.hpp"

#include <string>

FarmPrinter::FarmPrinter(Farm *farm)
:farm_(farm)
{}

std::string FarmPrinter::prettyPrint()
{
    std::string output = "";
    for(int i = 0; i < farm_->getNumberOfRows(); i++)
    {
        for(int j = 0; j < farm_->getNumberOfColumns(); j++)
        {
            output += farm_-> getSymbol(i, j);
            output += " ";
        }
    output += "\n";
    }
    return output;
}
