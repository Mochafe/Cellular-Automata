#pragma once

enum class CellType {
	Empty,
	Solid,
	Water
};

struct Cell
{
	Cell() : type(CellType::Empty) {}
	Cell(CellType type) : type(type) {}
	CellType type;
};
