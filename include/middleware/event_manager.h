#ifndef _EVENT_MANAGER_H
#define _EVENT_MANAGER_H

#include "middleware/asset_manager.h"

/*!
    @brief Singleton class that manages all inputs from
the player, returning events to the game class
which will act according to its current state.
*/
class EventManager
{
public:

    /*!
    @brief Registered input keys
    TODO: Still not being used
    */
    enum
    {
        NONE        = 100,

        RIGHT       = 72,
        LEFT        = 71,
        UP          = 73,
        DOWN        = 74,

        ESC         = 36,
        LEFT_SHIFT  = 38,
        LEFT_CTRL   = 37,
        SPACE       = 57,
        TAB         = 60,

        LEFT_MOUSE  = 0
    
    }typedef Keybinds;

public:
    /*!
    @brief Guarantee that AssetManager is a singleton, i.e., if it's the
    first class creation, Instance pointer receives this.
    If it's not, program stops execution.
    */
    EventManager();

    /*!
    @brief Clear loaded textures before program finish execution.
    */
    ~EventManager();

    /*!
    @brief Update all mouse positions on screen and check for input
    events. If an event happened, its returned to the game to
    handle it.
    @param wnd Current window
    @return Reference to the registered sf::Event.
    */
    static sf::Event* updateEvents(sf::RenderWindow* wnd);

    /*!
    @brief Checks if an input key is pressed.
    @param cmd Key that will be verified.
    @return True if it's pressed. False if it's not.
    */
    static bool keyPressed( unsigned int cmd );

    /*!
    @brief Checks if an input key was released.
    @param cmd Key that will be verified.
    @return True if it's pressed. False if it's not.
    */
    static bool keyReleased( unsigned int cmd );

    /*!
    @return Current mouse position in relation to
    the current window
    */
    static sf::Vector2i mouseWindowPosition();

    /*!
    @return Current mouse position in relation to
    the current screen
    */
    static sf::Vector2i mouseScreenPosition();

    /*!
    @return Current mouse position in relation to
    the current view
    */
    static sf::Vector2f mouseViewPosition();

private:
    /*!
    @brief Function called by updateEvents to actually poll
    events from the current window.
    @param wnd Current window.
    @return Reference to the registered event.
    */
    static sf::Event* updateSFML(sf::RenderWindow* wnd);

    /*!
    @brief Fuction called by updateEvents to update the current
    mouse position in relation to the current window, camera and
    its absolute position.
    @param wnd Current window.
    */
    static void updateMousePositions(sf::RenderWindow* wnd);

    /*! @brief Class instance */
    static EventManager* _m_Instance;

    /*! @brief Stores current sfml event */
    static sf::Event _sfmlEvent;

    /*! @brief Stores current mouse position in relation to the current window */
    static sf::Vector2i _mousePosWindow;

    /*! @brief Stores current mouse position in relation to the current screen */
    static sf::Vector2i _mousePosScreen;

    /*! @brief Stores current mouse position in relation to the current view */
    static sf::Vector2f _mousePosView;
};

#endif