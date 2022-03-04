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


	void ProcessCell(int index);
	void AddCell(sf::Vector2i pos, CellType type);
	void DeleteCell(sf::Vector2i pos);

	int PositionToIndex(sf::Vector2i& pos);
	sf::Vector2i IndexToPosition(int index);

	void SwapBuffer();
	

	std::vector<sf::RectangleShape> cellShape;

	std::unique_ptr<std::vector<Cell>> otherBuffer;
	std::unique_ptr<std::vector<Cell>> actualBuffer;

private:
	int size;
	std::vector<Cell> cellsBufferA, cellsBufferB;
};

