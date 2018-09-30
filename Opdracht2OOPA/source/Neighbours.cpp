#include "Neighbours.h"



Neighbours::Neighbours()
{
}

int Neighbours::countNeighbours(Grid grid, int gridSize, int x, int y) {
	int sum = 0;
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j ++) {
			int col = (x + i + (gridSize / 2)) % (gridSize / 2);
			int row = (y + j + (gridSize / 2)) % (gridSize / 2);
			sum += grid.grid[col][row];
		}
	}
	sum -= grid.grid[x][y];
	return sum;
}


Neighbours::~Neighbours()
{
}
