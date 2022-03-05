#pragma once
#include <SFML/Graphics.hpp>
class Tick
{
public:
	Tick(int maxTick);

	float TickPerSecond();

	bool IsTicking();
	
private:
	int maxTick, tick;

	sf::Clock timeSinceStart;
};

