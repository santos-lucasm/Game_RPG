#ifndef _MAIN_MENU_STATE_H
#define _MAIN_MENU_STATE_H

#include "state/state.h"
#include "entities/button.h"

class MainMenuState: public State
{
public:
    MainMenuState(sf::RenderWindow* window);
    ~MainMenuState();

    /*! @brief
        Should be called every frame to update user inputs
    and Entities alive on game.
    @param Time Time passed since last frame
    */
    void update(sf::Time& dt);

    /*! @brief
        Update user inputs to check for quit or TAB.
    @param Time Time passed since last frame
    */
    void updateInput();

    /*! @brief
        Should be called every frame to render Entities alive on game.
    @param target   Where the entities are going to be draw.
    */
    void render(sf::RenderTarget* target = nullptr);


private:

    sf::RectangleShape _background;
    Button* _playButton;

    /*! @property
    Traits flag that allow debug if class debug and tracer debug are active. */
    static const bool debugged = Traits<GameState>::debugged && Tracer::debugActive;

    /*! @property
    Traits flag that allow tracing if class tracing and tracer are active. */
    static const bool traced = Traits<GameState>::traced && Tracer::traceActive;
};

#endif