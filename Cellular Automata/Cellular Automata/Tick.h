#pragma once
#include <SFML/Graphics.hpp>
#include "Time.h"


class Tick
{
public:
	Tick();
	Tick(int tick , Time &time);

	bool isTick();
private:

	Time time;
	int maxTick;
};

