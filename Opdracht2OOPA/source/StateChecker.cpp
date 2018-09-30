#include "StateChecker.h"



StateChecker::StateChecker()
{
}

void StateChecker::checkState(Grid grid, Neighbours neighbours, int gridSize) {
	Grid _grid(gridSize);
	grid.drawGrid();
	for (int i = 0; i < gridSize / 2; i++) {
		for (int j = 0; j < gridSize / 2; j++) {
			int state = grid.grid[i][j];
			int n = neighbours.countNeighbours(grid, gridSize, i, j);
			if (state == 0 && n == 3) {
				_grid.grid[i][j] = 1;
			}
			else if (state == 1 && n < 2 || n > 3) {
				_grid.grid[i][j] = 0;
			}
			else {
				_grid.grid[i][j] = state;
			}
		}
	}
	grid = _grid;
}


StateChecker::~StateChecker()
{
}
