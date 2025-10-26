#pragma once

class Plot
{
public:
    virtual char getSymbol() const;
    virtual ~Plot() = 0;
    virtual void update();
    virtual bool isHarvestable();

protected:
    explicit Plot(char symbol);
    char symbol_;
    int dayCounter_;
    bool canHarvest_;
};
