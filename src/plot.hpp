#pragma once

constexpr char TILLED_SOIL_SYMBOL {'~'};

class Plot
{
public:
	virtual char getSymbol() const;
	virtual ~Plot() = 0;
	virtual void update();
	bool isHarvestable() const;
	bool hasBeenWatered() const;
	void setHasBeenWatered(bool watered);

protected:
	explicit Plot(char symbol, int daysToSprout, int daysToHarvest);
	char symbol_;
	int age_;
	bool canHarvest_;

	int daysToSprout_;
	int daysToHarvest_;
	bool hasBeenWatered_;
};
