#include "GridCell.h"
#include <random>
#include <iostream>


GridCell::GridCell() : cells(60 * 60, Cell()) {}

GridCell::GridCell(CellType type) : cells(60 * 60, Cell(type)){}

void GridCell::ModifyCell(sf::Vector2i pos, CellType type){
	if(pos.x < 60 && pos.x > 0 && pos.y < 60 && pos.y > 0 )
		cells[PositionToIndex(pos)].type = type;
}

void GridCell::ProcessCell() {
	
	for (int i = 0; i < cells.size(); i++) {

		switch (cells[i].type)
		{
		case CellType::Empty:
			break;

		case CellType::Solid:
			break;

		case CellType::Water:
		{
			sf::Vector2i pos{ IndexToPosition(i) };
			sf::Vector2i down{ pos + sf::Vector2i(0, 1) };
			if (InLimit(down)) {
				if (cells[PositionToIndex(down)].type == CellType::Empty) {
					cells[PositionToIndex(down)].type = CellType::Water;
					cells[i].type = CellType::Empty;
					break;
				}
			}

			sf::Vector2i right{ pos + sf::Vector2i(1, 0) };
			sf::Vector2i left{ pos - sf::Vector2i(1, 0) };

			if (InLimit(right) && InLimit(left)) {
				if (cells[PositionToIndex(right)].type == CellType::Empty && cells[PositionToIndex(left)].type == CellType::Empty) {
					std::random_device rd;
					std::mt19937 gen(rd());
					std::uniform_int_distribution<int> dis(0, 1);

					if (dis(gen) == 0) {
						cells[PositionToIndex(left)].type = CellType::Water;
						cells[i].type = CellType::Empty;
					}
					else {
						cells[PositionToIndex(right)].type = CellType::Water;
						cells[i].type = CellType::Empty;
					}

				}
				else if (cells[PositionToIndex(right)].type == CellType::Empty) {
					cells[PositionToIndex(right)].type = CellType::Water;
					cells[i].type = CellType::Empty;
				}
				else if (cells[PositionToIndex(left)].type == CellType::Empty) {
					cells[PositionToIndex(left)].type = CellType::Water;
					cells[i].type = CellType::Empty;
				}

			}
		}
			break;
		default:
			std::cout << "GridCell::ProcessCell() Error" << std::endl;
			break;
		}
	}
}

bool GridCell::InLimit(sf::Vector2i pos){
	return (pos.x < 60 && pos.x >= 0 && pos.y < 60 && pos.y > 0) ? true : false;
}


int GridCell::PositionToIndex(sf::Vector2i& pos) {
	return pos.x + 60 * pos.y;
}

sf::Vector2i GridCell::IndexToPosition(int index) {
	return sf::Vector2i(index % 60, index / 60);
}