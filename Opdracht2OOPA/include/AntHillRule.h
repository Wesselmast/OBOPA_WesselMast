#pragma once
#include "Grid.h"
#include "Neighbours.h"
#include <string>
#include <thread>

class AntHillRule
{
public:
	AntHillRule(int sleepTime, int resolution);
	~AntHillRule();
};

