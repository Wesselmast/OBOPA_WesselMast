#pragma once
#include <iostream>
#include <vector>

class Grid
{
private:
	char deadCell = 219;
	char liveCell = ' ';
public:
	std::vector<std::vector<int>> grid;
public:
	Grid(int gridSize);
	void drawGrid();
	~Grid();
};

