#include "state/state.h"

State::State()
{
}

State::~State()
{
}

std::string State::getName() const { return _name; }
void State::setName(std::string name) { _name = name; }