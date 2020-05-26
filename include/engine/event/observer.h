#ifndef _OBSERVER_H
#define _OBSERVER_H

#include "SFML/Window/Event.hpp"

class Observer
{
public:
    Observer() {}
    ~Observer() {}
    virtual void onNotify(sf::Event& event) = 0;
};

#endif