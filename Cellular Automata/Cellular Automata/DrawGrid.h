#pragma once
#include <memory>
#include "Grid.h"

class DrawGrid
{
public:
	void Draw(std::vector<Cell>& grid);

private:
	std::unique_ptr <std::vector<Cell>> gridPtr;
};

