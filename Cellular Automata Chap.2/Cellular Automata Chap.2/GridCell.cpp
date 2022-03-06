#include "GridCell.h"
#include <random>
#include <iostream>


GridCell::GridCell() : cellsBuffer(2, std::vector<Cell>(60 * 60, Cell())) {}

GridCell::GridCell(CellType type) : cellsBuffer(2, std::vector<Cell>(60 * 60, Cell(type))) {}

void GridCell::ModifyCell(sf::Vector2i pos, CellType type){
	if (pos.x < 60 && pos.x > 0 && pos.y < 60 && pos.y > 0) {
		cellsBuffer[buffer][PositionToIndex(pos)].type = type;
	}
		
		
}

void GridCell::ProcessCell() {	

	for (int i = 0; i < cellsBuffer[otherBuffer].size(); i++) {
		cellsBuffer[otherBuffer][i].type = CellType::Empty;
	}

	
	for (int i = 0; i < cellsBuffer[buffer].size(); i++) {

		switch (cellsBuffer[buffer][i].type)
		{
		case CellType::Empty:
			break;

		case CellType::Solid:
			cellsBuffer[otherBuffer][i].type = CellType::Solid;
			break;

		case CellType::Water:
		{
			sf::Vector2i pos{ IndexToPosition(i) };
			sf::Vector2i down{ pos + sf::Vector2i(0, 1) };
			if (InLimit(down)) {
				if (cellsBuffer[buffer][PositionToIndex(down)].type == CellType::Empty) {
					cellsBuffer[otherBuffer][PositionToIndex(down)].type = CellType::Water;
					break;
				}
			}

			sf::Vector2i right{ pos + sf::Vector2i(1, 0) };
			sf::Vector2i left{ pos - sf::Vector2i(1, 0) };

			if (InLimit(right) && InLimit(left)) {
				if (cellsBuffer[buffer][PositionToIndex(right)].type == CellType::Empty && cellsBuffer[buffer][PositionToIndex(left)].type == CellType::Empty &&
					cellsBuffer[otherBuffer][PositionToIndex(right)].type == CellType::Empty && cellsBuffer[otherBuffer][PositionToIndex(left)].type == CellType::Empty) {
					std::random_device rd;
					std::mt19937 gen(rd());
					std::uniform_int_distribution<int> dis(0, 1);

					if (dis(gen) == 0) {
						cellsBuffer[otherBuffer][PositionToIndex(left)].type = CellType::Water;
						break;
					}
					else {
						cellsBuffer[otherBuffer][PositionToIndex(right)].type = CellType::Water;
						break;
					}

				}
			}
			if (InLimit(right)) {
				if (cellsBuffer[buffer][PositionToIndex(right)].type == CellType::Empty && cellsBuffer[otherBuffer][PositionToIndex(right)].type == CellType::Empty) {
					cellsBuffer[otherBuffer][PositionToIndex(right)].type = CellType::Water;
					break;
				}
			}
			if (InLimit(left)) {
				if (cellsBuffer[buffer][PositionToIndex(left)].type == CellType::Empty && cellsBuffer[otherBuffer][PositionToIndex(left)].type == CellType::Empty) {
					cellsBuffer[otherBuffer][PositionToIndex(left)].type = CellType::Water;
					break;
				}
			}

			
			cellsBuffer[otherBuffer][i].type = CellType::Water;
				
			
		}
			break;
		default:
			std::cout << "GridCell::ProcessCell() Error" << std::endl;
			break;
		}
	}

	SwapBuffer();
}

bool GridCell::InLimit(sf::Vector2i pos){
	return (pos.x < 60 && pos.x > 0 && pos.y < 60 && pos.y > 0) ? true : false;
}


int GridCell::PositionToIndex(sf::Vector2i& pos) {
	return pos.x + 60 * pos.y;
}

sf::Vector2i GridCell::IndexToPosition(int index) {
	return sf::Vector2i(index % 60, index / 60);
}

void GridCell::SwapBuffer() {
	if (buffer == 0) {
		buffer = 1;
		otherBuffer = 0;
	}
	else {
		buffer = 0;
		otherBuffer = 1;
	}

}


