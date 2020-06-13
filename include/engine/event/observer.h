#ifndef _OBSERVER_H
#define _OBSERVER_H

#include "middleware/event_manager.h"

class Observer
{
public:
    Observer() {}
    ~Observer() {}
    virtual void onNotify(Machine& fsm, sf::Event& event) = 0;
};

#endif