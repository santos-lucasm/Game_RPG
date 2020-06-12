#include "state/player_state.h"
#include <iostream>

PlayerState::PlayerState(std::string name, unsigned int dir) { _name = name; _dir = dir; }

StandingState::StandingState(unsigned int dir): PlayerState("STANDING", dir) {}
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
            fsm.setState( new StandingState( id ) );
            fsm.setState( new WalkingState( id ) );
        }
    }
}

WalkingState::WalkingState(unsigned int dir): PlayerState("WALKING", dir) {}
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
            fsm.setState( new StandingState( id ) );
            fsm.setState( new WalkingState( id ) );
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

SprintingState::SprintingState(unsigned int dir): PlayerState("SPRINTING", dir) {}
void SprintingState::goNext(Machine& fsm, unsigned int id)
{
    /* None command received */
    if( id == 0 )
        fsm.exitState(); /* Pop Sprinting state and go to Walking */

    /* SprintCommand received */
    else if( id == 10 )
        return;

    /* Tried to change moving direction */
    else if( id < 5)
    {
        /*
        Needed for player changing direction holding LEFT_SHIFT,
        otherwise he would pop exitState and just push it again,
        without changing the movement direction.
        */
        if( id != getDirection() )
        {
            fsm.clearStack();
            fsm.setState( new StandingState( id ) );
            fsm.setState( new WalkingState( id ) );
            fsm.setState( new SprintingState( id ) );
        }
        else
            fsm.exitState();
    }
}