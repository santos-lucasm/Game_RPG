#include "state/player_state.h"
#include <iostream>

PlayerState::PlayerState(std::string name): _name(name) {}
std::string PlayerState::getName() const { return _name; }


StandingState::StandingState(): PlayerState("STANDING") {}
void StandingState::goNext(Machine& fsm)
{
    std::cout << "idle" << std::endl;
    /*
    if( !Command )
        return;
    else
        push WALKING
    */
}

WalkingState::WalkingState(): PlayerState("WALKING") {}
void WalkingState::goNext(Machine& fsm)
{
    std::cout << "andei" << std::endl;
    /*
    if( !Command )
        pop
    else if( Command = WALKING )
        pop all
        push IDLE_dir
        push WALKING_dir
    */
}

SprintingState::SprintingState(): PlayerState("SPRINTING") {}
void SprintingState::goNext(Machine& fsm)
{
    std::cout << "correndo" << std::endl;
    /*
    if( !Command )
        pop this
    else
        push SPRINTING_dir
    */
}