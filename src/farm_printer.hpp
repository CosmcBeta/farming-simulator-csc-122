#pragma once

#include "farm.hpp"

class FarmPrinter
{
public:
    FarmPrinter(Farm* farm);
    std::string prettyPrint();
    std::string printKey();
private:
    Farm* farm_;
};
