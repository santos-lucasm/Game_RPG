#ifndef _MACHINE_STATE_H
#define _MACHINE_STATE_H

#include "state/state.h"
#include <stack>
#include "engine/event/observer.h"

class Machine: public Observer
{
public:
    Machine( State* firstState );
    virtual ~Machine();

    /* Repass notify to the current State */
    void onNotify(Machine& fsm, sf::Event& event);
    /* Repass command to the current State */
    void goNext(Machine& fsm);

    /* Return current State */
    State* getState() const;

    /* Invoke a new current State */
    void setState( State* );

    /* Return if there's any State on FSM */
    bool isEmpty();

    /* Deletes the current State */
    void exitState();
    
private:
    std::stack<State*> _states;
};

#endif