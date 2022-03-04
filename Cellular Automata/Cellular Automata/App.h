#pragma once
#include "Grid.h"
#include "Tick.h"
#include "Time.h"
#include <SFML/Graphics.hpp>

class App
{
public:
	App(sf::RenderWindow& window);

	
	void Loop();

private:

	Grid grid;
	Tick tick;
	Time time;
	std::shared_ptr<sf::RenderWindow> window;
	std::shared_ptr<std::vector<sf::RectangleShape>> cellShape;
	int size{ 600 };

};

