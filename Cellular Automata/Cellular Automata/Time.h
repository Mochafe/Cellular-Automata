#pragma once

#include <SFML/Graphics.hpp>

class Time
{
public:

	Time();

	void CalculateDeltaTime();

	void UpdateTime();

	sf::Time GetDeltaTime();
	sf::Time GetTimeSinceStart();

private:
	sf::Clock timeSinceStartClock;
	sf::Clock deltaTimeClock;

	sf::Time timeSinceStart;
	sf::Time deltaTime;

};

