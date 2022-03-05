#pragma once
#include "Cell.h"
#include <vector>
#include <SFML/Graphics.hpp>


class GridCell
{
public:
	GridCell();
	GridCell(CellType type);

	void ModifyCell(sf::Vector2i pos, CellType type);

	void ProcessCell();

	bool InLimit(sf::Vector2i pos);

	std::vector<Cell> cells;

private:
	int PositionToIndex(sf::Vector2i& pos);

	sf::Vector2i IndexToPosition(int index);

};

