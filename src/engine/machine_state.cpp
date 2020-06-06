#include "engine/machine_state.h"

Machine::Machine( State* firstState )
{   
    if(firstState)
        setState( firstState );
    /* TODO: Throw exception */
}

Machine::~Machine()
{
    while( !isEmpty() )
        exitState();
}

void Machine::onNotify(Machine& fsm, sf::Event& event)
{
    getState()->onNotify(fsm, event);
}

void Machine::goNext(Machine& fsm)
{
    getState()->goNext(*this);
}

State* Machine::getState() const
{
    return _states.top();
}

void Machine::setState( State* state )
{
    _states.push( state );
}

bool Machine::isEmpty()
{
    if( _states.empty() )
        return true;
    return false;
}

void Machine::exitState()
{
    delete _states.top();
    _states.pop();
}