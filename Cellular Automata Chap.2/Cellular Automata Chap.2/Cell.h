#pragma once
enum class CellType
{
	Empty,
	Water,
	Solid
};

struct Cell
{
public:
	Cell() : type(CellType::Empty){}
	Cell(CellType type) : type(type) {}

	CellType type;
};