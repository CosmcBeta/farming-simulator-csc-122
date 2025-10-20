#include "src/farm.hpp"
#include "src/farm_printer.hpp"
#include "src/carrot.hpp"

#include <iostream>

int main()
{
    Farm farm(7, 8);
    FarmPrinter printer(&farm);
    std::cout << printer.prettyPrint() << std::endl;

    Carrot *carrot = new Carrot();
    farm.plant(1, 2, carrot);
    std::cout << printer.prettyPrint();
}
