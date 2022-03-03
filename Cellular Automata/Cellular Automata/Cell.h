#pragma once

enum class CellType {
	Empty,
	Solid,
	Water
};

struct Cell
{
	Cell(float pressure, CellType type) : type(type), pressure(pressure) {}
	CellType type;
	float pressure;

};
