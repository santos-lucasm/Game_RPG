#ifndef _PLAYER_STATE_H
#define _PLAYER_STATE_H

#include "state/state.h"
#include "engine/machine_state.h"

class PlayerState: public State
{

public:
    PlayerState(std::string name);
    virtual ~PlayerState() {}

    virtual void onNotify(Machine& fsm, sf::Event& event) = 0;
    void goNext(Machine& fsm) {}

    std::string getName() const;
private:
    std::string _name;
};

class StandingState: public PlayerState
{
public:
    StandingState();
    ~StandingState() {}
    virtual void onNotify(Machine& fsm, sf::Event& event) {}
    void goNext(Machine& fsm);
};

class WalkingState: public PlayerState
{
public:
    WalkingState();
    ~WalkingState() {}
    virtual void onNotify(Machine& fsm, sf::Event& event) {}
    void goNext(Machine& fsm);
};

class SprintingState: public PlayerState
{
public:
    SprintingState();
    ~SprintingState() {}
    virtual void onNotify(Machine& fsm, sf::Event& event) {}
    void goNext(Machine& fsm);
};

#endif