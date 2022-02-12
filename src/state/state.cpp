#include "state/state.h"

State::State()
{
}

State::~State()
{
}

std::string State::name() const
{
    return _name;
}

void State::name(std::string name)
{
    _name = name;
}