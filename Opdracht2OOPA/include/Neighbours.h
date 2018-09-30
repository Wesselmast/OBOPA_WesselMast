#pragma once
#include "Grid.h"

class Neighbours
{
public:
	Neighbours();
	int countNeighbours(Grid grid, int gridSize, int x, int y);
	~Neighbours();
};

