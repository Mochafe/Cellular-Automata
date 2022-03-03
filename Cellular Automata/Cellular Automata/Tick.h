#pragma once
#include <SFML/Graphics.hpp>


class Tick
{
public:
	Tick(int tick);

	void UpdateTick();
private:
	sf::Clock clock;
	int maxTick, tick;
};

