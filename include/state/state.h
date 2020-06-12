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
    virtual void goNext(Machine& fsm, unsigned int id) {}

    virtual std::string getName() const { return _name; }
    virtual void setName(std::string name) { _name = name; }
    virtual unsigned int getDirection() const { return 0; }

protected:
    std::string _name;
};

#endif