#pragma once

#include "plot.hpp"

#include <string>

class Soil : public Plot
{
public:
    std::string symbol() override;
};
