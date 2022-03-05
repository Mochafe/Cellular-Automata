#include "Tick.h"

Tick::Tick(int maxTick) : maxTick(maxTick), tick(0) {
	timeSinceStart.restart();
}

float Tick::TickPerSecond(){
	return tick / timeSinceStart.getElapsedTime().asSeconds();
}

bool Tick::IsTicking(){
	tick++;
	return (timeSinceStart.getElapsedTime().asMilliseconds() % 50 == 0) ? true : false;
}
