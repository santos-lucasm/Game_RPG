#include "state/player_state.h"
#include <iostream>

PlayerState::PlayerState(std::string name, Direction dir) { _name = name; _dir = dir; }

PlayerState::Direction PlayerState::chooseDirection(unsigned int id)
{
    switch (id)
    {
    case 1:
        return RIGHT; break;
    case 2:
        return LEFT; break;
    case 3:
        return UP; break;
    case 4:
        return DOWN; break;
    default:
        return NONE;
    }
}

StandingState::StandingState(Direction dir): PlayerState("STANDING", dir) {}
void StandingState::goNext(Machine& fsm, unsigned int id)
{   
    /* None command received */
    if( id == 0 )
        return;
    /* MoveCommand received */
    else if( id < 5)
    {
        /*  If player starts moving in the same direction he
        was standing */
        if( id == getDirection() )
            fsm.setState( new WalkingState( getDirection() ) );
        else
        {
            fsm.clearStack();
            fsm.setState( new StandingState( chooseDirection(id) ) );
            fsm.setState( new WalkingState( chooseDirection(id) ) );
        }
    }
}

WalkingState::WalkingState(Direction dir): PlayerState("WALKING", dir) {}
void WalkingState::goNext(Machine& fsm, unsigned int id)
{
    /* None command received */
    if( id == 0 )
        fsm.exitState(); /* Pop walking state and go to Standing */
    /* MoveCommand received */
    else if( id < 5)
    {
        /*  If the player is moving in another direction, pops the Standing
        and Walking states, then push new ones in the correct direction. */
        if( id != getDirection() )
        {
            fsm.clearStack();
            fsm.setState( new StandingState( chooseDirection(id) ) );
            fsm.setState( new WalkingState( chooseDirection(id) ) );
        }
        else
            return;
    }
    /* SprintCommand received */
    else if( id == 10)
    {
        fsm.setState( new SprintingState( getDirection() ) );
    }
}

SprintingState::SprintingState(Direction dir): PlayerState("SPRINTING", dir) {}
void SprintingState::goNext(Machine& fsm, unsigned int id)
{
    /* None command received */
    if( id == 0 )
        fsm.exitState(); /* Pop Sprinting state and go to Walking */

    /* SprintCommand received */
    else if( id == 10 )
        return;

    else
        fsm.exitState();
    /*
    else if( id < 5)
    {
        if( id != getDirection() )
        {
            fsm.exitState();
            fsm.exitState();
            fsm.exitState();
            fsm.setState( new StandingState( chooseDirection(id) ) );
            fsm.setState( new WalkingState( chooseDirection(id) ) );
            fsm.setState( new SprintingState( chooseDirection(id) ) );
        }
    }
    */
}