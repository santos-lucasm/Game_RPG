#include "clock.h"

void Clock::frameStart() { _dt = _clock.restart(); }
void Clock::setElapsedTime(){ _elapsed += _dt; }
sf::Time& Clock::getElapsedTime(){ return _elapsed; }
sf::Time& Clock::getDT() { return _dt; }