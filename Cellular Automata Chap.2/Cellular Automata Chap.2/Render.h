#pragma once
#include <SFML/Graphics.hpp>
#include "Cell.h"

class Render
{
public:
	Render(sf::RenderWindow* window);

	void GridToShape(std::vector<Cell>& cell);
	sf::Vector2i IndexToPos(int index);

	void Draw();
	void Clear();

private:
	sf::RenderWindow* window;
	std::vector<sf::RectangleShape> rectangles{};

};

