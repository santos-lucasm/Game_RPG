#ifndef _STATE_H
#define _STATE_H

// #include "engine/machine_state.h"
#include "engine/event/observer.h"

class State: public Observer
{
public:
    State();
    virtual ~State();
    virtual void update(sf::Time& dt);
    virtual void render(sf::RenderTarget* target = nullptr);

    virtual void onNotify(Machine& fsm, sf::Event& event) = 0;
    virtual void goNext(Machine& fsm) {}
};

#endif