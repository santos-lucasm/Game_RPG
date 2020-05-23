#ifndef _STATE_H
#define _STATE_H

#include "entities/player.h"

/*! @class
    State is a base class that every GameState on finite
state machine ou automata pushdown will have to inherit.
Game has a stack of states and keeps updating the top
of the stack.
*/
class State
{
public:
    /*! @brief
        State constructor, initializes the window.
    @param window Where this state will be drawing
    */
    State(sf::RenderWindow* window);

    /*! @brief
        Remembering this has to be virtual, to guarantee
    the flow of destructor on inheritance.
    */
    virtual ~State();

    /*! @brief
        Virtual method to be implemented by every State. Should be called
    every frame to update whatever is inside each State.
    @param Time Time passed since last frame
    */
    virtual void update(sf::Time& dt) = 0;

    /*! @brief
        Virtual method to be implemented by every State. Should be called
    every frame to render (draw) State on the screen.
    @param target   Where the entity is going to be draw.
    */
    virtual void render(sf::RenderTarget* target = nullptr) = 0;

    /*! @brief
    @return Returns the _quit flag.
    */
    const bool& getQuit() const;

    /*! @brief
        Checks if this state received a command to be closed.
    */
    void checkQuit();

    sf::RenderWindow* getWindow() { return _window; }

protected:
    /*! @property
    Window passed by game on state creation, it's where that state will draw. */
    sf::RenderWindow* _window;

    /*! @property
    Indicates if this state wants to be closed. */
    bool _quit;
private:
    /*! @property
    Traits flag that allow debug if class debug and tracer debug are active. */
    static const bool debugged = Traits<State>::debugged && Tracer::debugActive;

    /*! @property
    Traits flag that allow tracing if class tracing and tracer are active. */
    static const bool traced = Traits<State>::traced && Tracer::traceActive;
};

#endif