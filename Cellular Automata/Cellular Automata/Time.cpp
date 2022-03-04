#include "Time.h"

Time::Time() { timeSinceStartClock.restart(); };

void Time::CalculateDeltaTime()
{
    deltaTime = deltaTimeClock.restart();
}

void Time::UpdateTime() {
    CalculateDeltaTime();
}

sf::Time Time::GetTimeSinceStart() {
    return timeSinceStartClock.getElapsedTime();
}

sf::Time Time::GetDeltaTime()
{
    return deltaTimeClock.getElapsedTime();
}

