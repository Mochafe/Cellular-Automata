#include "Render.h"
#include <iostream>

Render::Render(sf::RenderWindow* window) : window(window){}

void Render::GridToShape(std::vector<Cell>& cell) {

	rectangles.clear();


	for (int i{ 0 }; i != cell.size(); i++) {
		switch (cell[i].type)
		{
		case CellType::Empty:
			break;

		case CellType::Solid:
		{
			rectangles.push_back(sf::RectangleShape(sf::Vector2f(10, 10)));
			rectangles[rectangles.size() - 1].setPosition(IndexToPos(i).x, IndexToPos(i).y);
			rectangles[rectangles.size() - 1].setFillColor(sf::Color(128, 128, 128, 255));
		}
		break;

		case CellType::Water:
		{
			rectangles.push_back(sf::RectangleShape(sf::Vector2f(10, 10)));
			rectangles[rectangles.size() - 1].setPosition(IndexToPos(i).x, IndexToPos(i).y);
			rectangles[rectangles.size() - 1].setFillColor(sf::Color::Blue);
		}
		break;
		default:
			std::cout << "Error in Render::GridToShape" << std::endl;
			break;
		}
	}
}

sf::Vector2i Render::IndexToPos(int index)
{
	return sf::Vector2i(index % 60, index / 60) * 10;
}


void Render::Draw() {
	if (rectangles.size() != 0) {
		for (auto shape : rectangles) {
			window->draw(shape);
		}
	}
}

void Render::Clear(){
	rectangles.clear();
}
