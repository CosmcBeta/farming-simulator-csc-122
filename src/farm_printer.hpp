#pragma once

#include "farm.hpp"

class FarmPrinter
{
public:
    FarmPrinter(Farm *farm);
    std::string pp();
private:
    Farm *farm;
};
