#include "Grid.h"

Grid::Grid(int gridSize) {
	grid.resize(gridSize / 2);
	for (int i = 0; i < grid.size(); i++) {
		grid[i].resize(gridSize / 2);
		for (int j = 0; j < grid[i].size(); j++) {
			grid[i][j] = rand() % 2;
		}
	}
}

void Grid::drawGrid() {
	for (int i = 0; i < grid.size(); i++){
		for (int j = 0; j < grid[i].size(); j++) {
			if (grid[i][j] == 0) {
				std::cout << liveCell;
			}
			else {
				std::cout << deadCell;
			}
		}
		std::cout << std::endl;
	}
}

Grid::~Grid()
{
}
