#include "Tick.h"

Tick::Tick() : maxTick(20){
	time = Time();
}

Tick::Tick(int maxTick, Time& time) : maxTick(maxTick), time(time) {}


bool Tick::isTick()
{
	return (time.GetTimeSinceStart().asMilliseconds() % 1000 / maxTick == 0) ? true : false;
}

