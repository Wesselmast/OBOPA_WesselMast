#pragma once
#include "Grid.h"
#include "Neighbours.h"
#include <string>
#include <thread>

class SpeedUpRule
{
public:
	SpeedUpRule(int sleepTime, int resolution);
	~SpeedUpRule();
};

