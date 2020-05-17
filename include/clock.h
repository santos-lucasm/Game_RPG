#ifndef _CLOCK_H
#define _CLOCK_H

#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

#include "utilities/tracer.h"

class Clock
{
public:
    /*! @brief
        It's called on the start of the game loop, right before the event handling.
    Get the last frame duration, setting internal dt parameters to the clock return.
    */
    void updateDt();

    /*! @brief
        Called in every iteration of gameLoop, increasing the game elapsed time
    by the dt amount (current frame duration). Should be called after long operations
    and event handling.
    */
    void updateElapsed();

    /*! @brief
        Can be useful when showing time passed playing or when saving game files.
    @return
        Returns time passed since the game start.
    */
    sf::Time& getElapsed();

    /*! @brief
        Very useful to be passed to update methods on entities.
    @return
        Returns time passed since the last frame start.
    */
    sf::Time& getDT();

private:
    /*! @property
    Used to get the last frame duration. */
    sf::Clock _clock;

    /*! @property
    Measure time passed since game start. */
    sf::Time _elapsed;

    /*! @property
    Stores last frame duration */
    sf::Time _dt;

    /*! @property
    Traits flag that allow debug if class debug and tracer debug are active. */
    static const bool debugged = Traits<Clock>::debugged && Tracer::debugActive;

    /*! @property
    Traits flag that allow tracing if class tracing and tracer are active. */
    static const bool traced = Traits<Clock>::traced && Tracer::traceActive;
};

#endif