#include "engine/clock.h"

void Clock::updateDeltaTime()
{
    _dt = _clock.restart();
}

void Clock::updateElapsed()
{
    _elapsed += _dt;
}

sf::Time& Clock::elapsedTime()
{
    return _elapsed;
}

sf::Time& Clock::deltaTime()
{
    return _dt;
}