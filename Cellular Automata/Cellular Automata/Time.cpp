#include "Time.h"


void Time::CalculateDeltaTime()
{
    deltaTime = deltaTimeClock.restart();
}

float Time::GetDeltaTime()
{
    return deltaTime.asMicroseconds();
}

