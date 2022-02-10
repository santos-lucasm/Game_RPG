#include "engine/machine_state.h"
#include <iostream>

Machine::Machine( State* firstState )
{   
    if(firstState)
        setState( firstState );
    /* TODO: Throw exception */
}

Machine::~Machine()
{
    clearStack();
}

void Machine::goNext(Machine& fsm)
{
    getState()->goNext(fsm);
}

void Machine::goNext(unsigned int id)
{
    getState()->goNext(*this, id);
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

void Machine::clearStack()
{
    while( !isEmpty() )
        exitState();
}