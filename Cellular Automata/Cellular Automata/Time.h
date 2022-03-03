#pragma once

#include <SFML/Graphics.hpp>

class Time
{
public:

	void CalculateDeltaTime();

	float GetDeltaTime();

	sf::Clock deltaTimeClock;

	sf::Time deltaTime;

};

