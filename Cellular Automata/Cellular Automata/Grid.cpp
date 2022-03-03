#include "Grid.h"
#include <iostream>
#include <stdexcept>

Grid::Grid() : cellsBufferA(60 * 60, Cell(0, CellType::Empty)), cellsBufferB(60 * 60, Cell(0, CellType::Empty)), size(60) {}

Grid::Grid(size_t size) : cellsBufferA(size * size, Cell(0, CellType::Empty)), cellsBufferB(size * size, Cell(0, CellType::Empty)), size(size){}

void Grid::EvaluateCell(sf::Vector2i& pos) {

	switch (actualBuffer.get()->at(PositionToIndex(pos)).type) {

	case CellType::Empty:
		break;

	case CellType::Solid:

		break;
	case CellType::Water:

		break;
	default:
		throw std::runtime_error("Celltype error in EvaluateCell");
		break;
	}
}

int Grid::PositionToIndex(sf::Vector2i& pos)
{
	return pos.x + size * pos.y;
}

sf::Vector2i Grid::IndexToPosition(int index) {
	return sf::Vector2i(index % size, index / size);
}

void Grid::SwapBuffer() {

	if (actualBuffer.get() == &cellsBufferA)
		actualBuffer.reset(&cellsBufferB);

	else actualBuffer.reset(&cellsBufferA);
}
