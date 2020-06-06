#ifndef _OBSERVER_H
#define _OBSERVER_H

class Machine;
#include "SFML/Window/Event.hpp"

class Observer
{
public:
    Observer() {}
    ~Observer() {}
    virtual void onNotify(Machine& fsm, sf::Event& event) = 0;
};

#endif