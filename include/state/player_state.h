#ifndef _PLAYER_STATE_H
#define _PLAYER_STATE_H

#include "state/state.h"
#include "engine/machine_state.h"

class PlayerState: public State
{
public:
    enum Direction{ NONE, RIGHT, LEFT, UP, DOWN };

public:
    PlayerState(std::string name, unsigned int dir);
    virtual ~PlayerState();

    virtual void onNotify(Machine& fsm, sf::Event& event) = 0;
    void goNext(Machine& fsm, unsigned int id) {}

    unsigned int getDirection() const { return _dir; }
    unsigned int cmdDirection(int cmd) const;
    bool checkMovement(int cmd);
protected:
    unsigned int _dir;
};

class StandingState: public PlayerState
{
public:
    StandingState(unsigned int dir);
    ~StandingState() {}
    virtual void onNotify(Machine& fsm, sf::Event& event) {}
    void goNext(Machine& fsm, unsigned int id);
};

class WalkingState: public PlayerState
{
public:
    WalkingState(unsigned int dir);
    ~WalkingState() {}
    virtual void onNotify(Machine& fsm, sf::Event& event) {}
    void goNext(Machine& fsm, unsigned int id);
};

class SprintingState: public PlayerState
{
public:
    SprintingState(unsigned int dir);
    ~SprintingState() {}
    virtual void onNotify(Machine& fsm, sf::Event& event) {}
    void goNext(Machine& fsm, unsigned int id);
};

#endif