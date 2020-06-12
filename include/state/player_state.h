#ifndef _PLAYER_STATE_H
#define _PLAYER_STATE_H

#include "state/state.h"
#include "engine/machine_state.h"

class PlayerState: public State
{
public:
    PlayerState(std::string name, Direction dir);
    virtual ~PlayerState() {}

    virtual void onNotify(Machine& fsm, sf::Event& event) = 0;
    void goNext(Machine& fsm, unsigned int id) {}

    Direction chooseDirection(unsigned int id);
};

class StandingState: public PlayerState
{
public:
    StandingState(Direction dir);
    ~StandingState() {}
    virtual void onNotify(Machine& fsm, sf::Event& event) {}
    void goNext(Machine& fsm, unsigned int id);
};

class WalkingState: public PlayerState
{
public:
    WalkingState(Direction dir);
    ~WalkingState() {}
    virtual void onNotify(Machine& fsm, sf::Event& event) {}
    void goNext(Machine& fsm, unsigned int id);
};

class SprintingState: public PlayerState
{
public:
    SprintingState(Direction dir);
    ~SprintingState() {}
    virtual void onNotify(Machine& fsm, sf::Event& event) {}
    void goNext(Machine& fsm, unsigned int id);
};

#endif