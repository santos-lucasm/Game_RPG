#ifndef _STATE_H
#define _STATE_H

#include "engine/event/observer.h"

class State: public Observer
{
public:
    /* Pass string on constructor */
    State();
    virtual ~State();

    virtual void update(sf::Time& dt) {}
    virtual void render(sf::RenderTarget* target = nullptr) {}
    virtual void onNotify(Machine& fsm, sf::Event& event) = 0; /* Used on GameStates */
    virtual void goNext(Machine& fsm, unsigned int id) {} /* Used on PlayerStates */

    std::string getName() const;
    void setName(std::string name);

    /* TODO: Think about this method */
    virtual unsigned int getDirection() const { return 0; }

protected:
    std::string _name;
};

#endif