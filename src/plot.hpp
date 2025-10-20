#pragma once

class Plot
{
public:
    virtual char getSymbol() const;
    virtual ~Plot() = 0;

protected:
    Plot(char symbol);
    char symbol_;
};
