#include "Grid.h"
#include <iostream>
#include <stdexcept>

Grid::Grid() : cellsBufferA((size_t)(60 * 60), Cell( CellType::Empty)), cellsBufferB(60 * 60, Cell(CellType::Empty)), size(60) { actualBuffer = std::unique_ptr<std::vector<Cell>>(&cellsBufferA); otherBuffer = std::unique_ptr<std::vector<Cell>>(&cellsBufferB);
}

Grid::Grid(size_t size) : cellsBufferA(size * size, Cell(CellType::Empty)), cellsBufferB(size * size, Cell(CellType::Empty)), size(size){ actualBuffer = std::unique_ptr<std::vector<Cell>>(&cellsBufferA); otherBuffer = std::unique_ptr<std::vector<Cell>>(&cellsBufferB); }


void Grid::ProcessCell(int index) {

	switch (actualBuffer.get()->at(index).type) {

	case CellType::Empty:
		if (otherBuffer.get()->at(index).type == CellType::Empty) break;
		else {
			actualBuffer.get()->at(index).type = CellType::Empty;
			otherBuffer.get()->at(index).type = CellType::Empty;
		}
		break;

	case CellType::Solid:
		if (otherBuffer.get()->at(index).type == CellType::Solid) break;
		else {
			actualBuffer.get()->at(index).type = CellType::Empty;
			otherBuffer.get()->at(index).type = CellType::Solid;
			sf::RectangleShape temp(sf::Vector2f(10, 10));
			temp.setFillColor(sf::Color::Red);
			temp.setPosition(sf::Vector2f(IndexToPosition(index).x - 5, IndexToPosition(index).y - 5));
			cellShape.push_back(temp);
		}

		break;

	case CellType::Water:
	{
		sf::Vector2i pos{ IndexToPosition(index) };
		sf::Vector2i down{ pos + sf::Vector2i(0, -1) };

		if (otherBuffer.get()->at(PositionToIndex(down)).type == CellType::Water);
		else {
			actualBuffer.get()->at(index).type = CellType::Empty;
			otherBuffer.get()->at(PositionToIndex(down)).type = CellType::Water;
			sf::RectangleShape temp(sf::Vector2f(10, 10));
			temp.setFillColor(sf::Color::Blue);
			temp.setPosition(sf::Vector2f(down.x - 5, down.y - 5));
			cellShape.push_back(temp);
			break;
		}

		sf::Vector2i right{ pos + sf::Vector2i(1, 0) };

		if (otherBuffer.get()->at(PositionToIndex(right)).type == CellType::Water);
		else {
			actualBuffer.get()->at(index).type = CellType::Empty;
			otherBuffer.get()->at(PositionToIndex(right)).type = CellType::Water;
			sf::RectangleShape temp(sf::Vector2f(10, 10));
			temp.setFillColor(sf::Color::Blue);
			temp.setPosition(sf::Vector2f(right.x - 5, right.y - 5));
			cellShape.push_back(temp);
			break;
		}

		sf::Vector2i left{ pos + sf::Vector2i(-1, 0) };

		if (otherBuffer.get()->at(PositionToIndex(left)).type == CellType::Water);
		else {
			actualBuffer.get()->at(index).type = CellType::Empty;
			otherBuffer.get()->at(PositionToIndex(left)).type = CellType::Water;
			sf::RectangleShape temp(sf::Vector2f(10, 10));
			temp.setFillColor(sf::Color::Blue);
			temp.setPosition(sf::Vector2f(left.x - 5, left.y - 5));
			cellShape.push_back(temp);
			break;
		}
	}
		break;

	default:
		throw std::runtime_error("Celltype error in EvaluateCell");
		break;
	}
}

void Grid::AddCell(sf::Vector2i pos, CellType type) {
	otherBuffer.get()->at(PositionToIndex(pos)).type = type;
}

void Grid::DeleteCell(sf::Vector2i pos) {
	otherBuffer.get()->at(PositionToIndex(pos)).type = CellType::Empty;
}

int Grid::PositionToIndex(sf::Vector2i& pos) {
	return pos.x + size * pos.y;
}

sf::Vector2i Grid::IndexToPosition(int index) {
	return sf::Vector2i(index % size, index / size);
}

void Grid::SwapBuffer() {

	if (actualBuffer.get() == &cellsBufferA) {
		otherBuffer.reset(&cellsBufferA);
		actualBuffer.reset(&cellsBufferB);
	}
		

	else {
		otherBuffer.reset(&cellsBufferB);
		actualBuffer.reset(&cellsBufferA);
	}
}


