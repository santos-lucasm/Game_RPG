#ifndef _STATE_H
#define _STATE_H

#include "engine/component/inputs/player_input.h"
#include "engine/component/graphics/player_graphics.h"
#include "engine/component/physics/player_physics.h"

#include "engine/event/observer.h"

class State: public Observer
{
public:
    State();
    virtual ~State();

    virtual void update(sf::Time& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
    virtual void onNotify(Machine& fsm, sf::Event& event) = 0;

private:
    static const bool debugged = Traits<State>::debugged && Tracer::debugActive;
    static const bool traced = Traits<State>::traced && Tracer::traceActive;
};

#endif