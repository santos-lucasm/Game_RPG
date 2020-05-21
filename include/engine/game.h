#ifndef _GAME_H
#define _GAME_H

#include "state/game_state.h"
#include "manager/asset_manager.h"
#include "clock.h"

/*! @class
    Provides methods to settings configuration, menus,
map trees and updates. Responsible for game loop and
event handling.
    One instance created at main.cpp, on a new game start.
*/
class Game
{
public:
    /*! @brief
        Initializes the window screen and
    the game states, then calls
    AssetManager and Clock creation.
    */
    Game();

    /*! @brief
        Saves screen settings on a .ini file, and then proceeds
    to destroy dynamically alocated memory.
        Every member of the Entity* list, then deletes the
    list nodes, finishes by deleting AssetManager and clock instances.
    */
    ~Game();

    /*! @brief
        Calls updateSFMLEvents to check for keybinds input,
    then calls update method for stack top State. Thus, verifies
    if the current State wants to exit (by pressing ESC) and removing
    it from the Stack.
    */
    void update();

    /*! @brief
        Handle IO, time and window events, taking actions
    or updating Entities according with entries.
    */
    void updateSFMLEvents();

    /*! @brief
        Calls render method for the stack top State.
    */
    void render();

    /*! @brief
        The game loop itself, should call all other important methods
    to update screen, entities, maps and handlers.
        Works on following order: clockReset -> update -> render.
    */
    void gameLoop();

private:
    /*! @brief
        Tries to open a window.ini file to get last used screen
    setting and create a new window using them.
        If the file couldn't be opened, the game window is created
    using the standard defined parameters.
    */
    void initWindow();

    /*! @brief
    Creates and add to the stack the first states
    of the game, like MainMenuState and GameState
    */
    void initState();

    /*! @property
    Stack of States to maintain a reference about what's running */
    std::stack<State*> _states;

    /*! @property
    Singleton instance of AssetManager, manages every game texture. */
    AssetManager * _manager;

    /*! @property
    Clock class will store data about the frame and game duration. */
    Clock * _clock;

    /*! @property
    A RenderWindow object reference, used to configure, draw and display. */
    sf::RenderWindow * _window;

    /*! @property
    Stores last event to be handle by the updateSFMLEvent method */
    sf::Event _event;

    /*! @property
    Traits flag that allow debug if class debug and tracer debug are active. */
    static const bool debugged = Traits<Game>::debugged && Tracer::debugActive;

    /*! @property
    Traits flag that allow tracing if class tracing and tracer are active. */
    static const bool traced = Traits<Game>::traced && Tracer::traceActive;
};
#endif