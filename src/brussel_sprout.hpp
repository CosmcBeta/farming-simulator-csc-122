#pragma once

#include "plot.hpp"

class BrusselSprout : public Plot
{
public:
	BrusselSprout();
	void update() override;
};
