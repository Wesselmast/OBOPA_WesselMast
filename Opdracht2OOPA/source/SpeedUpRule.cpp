#include "SpeedUpRule.h"

SpeedUpRule::SpeedUpRule(int sleepTime, int resolution)
{
	Grid grid(resolution);
	Neighbours neighbours;
	for (;;) {
		std::cout << std::string(5, '\n');

		Grid _grid(resolution);
		grid.drawGrid();
		for (int i = 0; i < resolution / 2; i++) {
			for (int j = 0; j < resolution / 2; j++) {
				int state = grid.grid[i][j];
				int n = neighbours.countNeighbours(grid, resolution, i, j);
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
		std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
		
		if (sleepTime > 0) {
			sleepTime -= 100;
		}
	}
}

SpeedUpRule::~SpeedUpRule()
{
}
