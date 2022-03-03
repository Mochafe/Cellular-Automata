#pragma once

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Cell.h"


class Grid
{
public:
	Grid();
	Grid(size_t size);

	void EvaluateCell(sf::Vector2i& pos);

	int PositionToIndex(sf::Vector2i& pos);
	sf::Vector2i IndexToPosition(int index);

	void SwapBuffer();


private:
	const int size;
	std::unique_ptr<std::vector<Cell>> actualBuffer;
	std::vector<Cell> cellsBufferA, cellsBufferB;
};

