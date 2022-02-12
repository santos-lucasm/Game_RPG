#ifndef _CLOCK_H
#define _CLOCK_H

#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

class Clock
{
public:
    /*!
    @brief It's called at the start of the game loop, right before the event handling.
    Gets the last frame duration and sets internal dt parameters to the clock return.
    */
    void updateDeltaTime();

    /*!
    @brief Called in every iteration of gameLoop, increasing the game elapsed time
    by the dt amount (current frame duration). Should be called after long operations
    and event handling.
    */
    void updateElapsed();

    /*!
    @brief Can be useful when showing time passed playing or when saving game files.
    @return Returns time passed since the game start.
    */
    sf::Time& elapsedTime();

    /*!
    @brief Very useful to be passed to update methods on entities.
    @return  Returns time passed since the last frame start.
    */
    sf::Time& deltaTime();

private:
    /*! @brief sfml clock used for time measurement. */
    sf::Clock _clock;

    /*! @brief Measure time passed since game start. */
    sf::Time _elapsed;

    /*! @brief Stores last frame duration */
    sf::Time _dt;
};

#endif