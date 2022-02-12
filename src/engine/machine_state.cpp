#include "engine/machine_state.h"
#include <iostream>

Machine::Machine( State* firstState )
{   
    if(firstState)
        state( firstState );
    /* TODO: Else: Throw exception */
}

Machine::~Machine()
{
    finishMachine();
}

State* Machine::state() const
{
    return _states.top();
}

void Machine::state( State* state )
{
    _states.push( state );
}

bool Machine::isEmpty()
{
    if( _states.empty() )
        return true;
    return false;
}

void Machine::goNext(Machine& fsm)
{
    state()->goNext(fsm);
}

void Machine::goNext(unsigned int id)
{
    state()->goNext(*this, id);
}

void Machine::exitState()
{
    delete _states.top();
    _states.pop();
}

void Machine::finishMachine()
{
    while( !isEmpty() )
        exitState();
}