#include "engine/clock.h"

void Clock::updateDt() { _dt = _clock.restart(); }
void Clock::updateElapsed(){ _elapsed += _dt; }
sf::Time& Clock::getElapsed(){ return _elapsed; }
sf::Time& Clock::getDT() { return _dt; }