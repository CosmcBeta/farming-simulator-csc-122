#pragma once

#include "farm.hpp"

class FarmPrinter
{
public:
    FarmPrinter(Farm* farm);
    std::string prettyPrint();
private:
    Farm* farm_;
};
