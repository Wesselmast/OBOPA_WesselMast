#pragma once
#include "Grid.h"
#include "Neighbours.h"
#include <string>
#include <thread>

class BaseRule
{
public:
	BaseRule(int sleepTime, int resolution);
	~BaseRule();
};

