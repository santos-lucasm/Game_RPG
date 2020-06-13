#include "state/player_state.h"
#include <iostream>

PlayerState::PlayerState(std::string name, unsigned int dir)
{
    db<PlayerState>(TRC) << "PlayerState() @ " << this << "\n";
    _name = name;
    _dir = dir;
}

PlayerState::~PlayerState()
{
    db<PlayerState>(TRC) << "~PlayerState() @ " << this << "\n";
}

unsigned int PlayerState::cmdDirection(int cmd) const
{
    switch (cmd)
    {
    case 71:
        return LEFT; break;
    case 72:
        return RIGHT; break;
    case 73:
        return UP; break;
    case 74:
        return DOWN; break;
    default:
        return -1;
    }
}

bool PlayerState::checkMovement(int cmd)
{
    if( cmd > 70 && cmd < 75 )
        return true;
    return false;
}

StandingState::StandingState(unsigned int dir): PlayerState("STANDING", dir)
{
    db<PlayerState>(TRC) << "StandingState() @ to direction " << dir << "\n";
}

void StandingState::goNext(Machine& fsm, unsigned int id)
{   
    /* None command received */
    if( id == 0 )
        return;
    
    else if( checkMovement(id) )
    {
        /*  If player starts moving in the same direction he
        was standing */
        if( cmdDirection(id) == getDirection() )
        {
            fsm.setState( new WalkingState( getDirection() ) );
        }
        else
        {
            fsm.clearStack();
            fsm.setState( new StandingState( cmdDirection(id) ) );
            fsm.setState( new WalkingState( cmdDirection(id) ) );
        }
    }
}

WalkingState::WalkingState(unsigned int dir): PlayerState("WALKING", dir)
{
    db<PlayerState>(TRC) << "WalkingState() @ to direction " << dir << "\n";
}

void WalkingState::goNext(Machine& fsm, unsigned int id)
{
    /* None command received */
    if( id == 0 )
        fsm.exitState(); /* Pop walking state and go to Standing */

    else if( checkMovement(id) )
    {
        /*  If the player is moving in another direction, pops the Standing
        and Walking states, then push new ones in the correct direction. */
        if( cmdDirection(id) != getDirection() )
        {
            fsm.clearStack();
            fsm.setState( new StandingState( cmdDirection(id) ) );
            fsm.setState( new WalkingState( cmdDirection(id) ) );
        }
        else
            return;
    }
    /* SprintCommand received */
    else if( id == 38)
    {
        fsm.setState( new SprintingState( getDirection() ) );
    }
}

SprintingState::SprintingState(unsigned int dir): PlayerState("SPRINTING", dir)
{
    db<PlayerState>(TRC) << "SprintingState() @ to direction " << dir << "\n";
}

void SprintingState::goNext(Machine& fsm, unsigned int id)
{
    /* None command received */
    if( id == 0 )
        fsm.exitState(); /* Pop Sprinting state and go to Walking */

    /* SprintCommand received */
    else if( id == 38 )
        return;

    /* Tried to change moving direction */
    else if( checkMovement(id) )
    {
        /*
        Needed for player changing direction holding LEFT_SHIFT,
        otherwise he would pop exitState and just push it again,
        without changing the movement direction.
        */
        if( cmdDirection(id) != getDirection() )
        {
            fsm.clearStack();
            fsm.setState( new StandingState( cmdDirection(id) ) );
            fsm.setState( new WalkingState( cmdDirection(id) ) );
            fsm.setState( new SprintingState( cmdDirection(id) ) );
        }
        /*
            This is to fix releasing LEFT_SHIFT and keeping
        running without releasing current arrowkey.
            TODO: pop currentState when LEFT_SHIFT Release.
        */
        else
            fsm.exitState();
    }
}