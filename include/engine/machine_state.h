#ifndef _MACHINE_STATE_H
#define _MACHINE_STATE_H

#include "state/state.h"
#include <stack>

class Machine
{
public:

    /*!
    @brief Machine is created by setting its first state.
    @param firstState Initial state of the machine.
    */
    Machine( State* firstState );

    /*!
    @brief Finish all the stored states.
    */
    virtual ~Machine();

    /*!
    @return Current state.
    */
    State* state() const;

    /*!
    @brief Set a new state for the machine.
    @param state New state to be added to machine.
    */
    void state( State* state);

    /*!
    @brief Checks if the stack of states is empty.
    @return True if there's any state, otherwise, returns false. */
    bool isEmpty();

    /*!
    @brief Repass an event command to the current state.
    @param fsm Machine to go to its next state.
    */
    void goNext(Machine& fsm);

    /*!
    @brief Repass an event command to the current state.
    @param id Next state id, used by this state machine.
    */
    void goNext(unsigned int id);

    /*!
    @brief Deletes the current State and removes it from the stack.
    */
    void exitState();

    /*!
    @brief Exit from all the states.
    */
    void finishMachine();
    
private:
    /*! @brief Stack used to store all the current states */
    std::stack<State*> _states;
};

#endif