#ifndef _APPLICATION_H
#define _APPLICATION_H

#include "engine/machine_state.h"
#include "state/main_menu_state.h"

#include "middleware/event_manager.h"
#include "clock.h"

/*!
    @brief Application class is used by programmer entry point, i.e. main
function, to create its application. It handles window creation, rendering,
entities creation, assets and event handling, etc.
    TODO: Later this will be an API for the user to create entities,
windows and cameras.
*/
class Application
{
public:
    /*!
    @brief Initializes Assets and Event manager, internal application clock
    and its window (by calling initWindow private function).
    Starts application FSM choosing an initial state.
    */
    Application();

    /*!
    @brief Saves current window size, and a presset of FPS, v-sync and mouse
    visibility to an configuration file, which will be read at the game new fresh
    start to configurate the new created window again.
    After that, it handles all the dynamic memory allocated of the created managers.
    */
    ~Application();

    /*!
    @brief Application loop that updates all entities and states, draw at the
    current window. All this is done using the internal clock, to prevent machine
    differences.
    */
    void run();
    
private:

    /*!
    @brief At application start, it checks for a standard configuration file,
    if it exists, the application window is created using its configurations.
    Otherwise, creates a windows using predefined configurations.
    */
    void initWindow();

    /*!
    @brief Update application checking for events and than updating the
    current state machine for that.
    */
    void update();

    /*!
    @brief Responsible for drawing the next frame and rendering it
    according to the current machine state.
    */
    void render();

    /*! @brief Application sfml window reference */
    sf::RenderWindow* _window;

    /*! @brief Application internal clock */
    Clock* _clock;

    /*! @brief Application FSM to handle current states (changing menus and etc) */ 
    Machine* _fsm;

    /*! @brief Responsible for setting textures for created entities */
    AssetManager* _m_Asset;

    /*! @brief Constantly checks for events and returns it for the application to handle it*/ 
    EventManager* _m_Event;
};
#endif