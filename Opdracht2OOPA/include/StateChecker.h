#pragma once
#include "Neighbours.h"
class StateChecker
{
public:
	StateChecker();
	void checkState(Grid grid, Neighbours neighbours, int gridSize);
	~StateChecker();
};

