#ifndef _GAME_H
#define _GAME_H

#include <list>

#include "entities/player.h"
#include "manager/asset_manager.h"

/*! @class
    Provides methods to settings configuration, menus,
map trees and updates. Responsible for game loop and
event handling.
    One instance created at main.cpp, on a new game start.
*/
class Game
{
public:
    /*!
    @brief
        Gets current screen configuration utilized by user
    and uses it to create a new window. If the string passed
    is empty, constructor locks on an assert.
    @param string   Title of new window
    */
    Game( std::string );

    /*!
    @brief
        Delete every member of the Entity* list, then deletes
    the list nodes, finishes by deleting AssetManager instance.
    */
    ~Game();

    /*!
    @brief
        Currently sets standard window configuration.
        Sets framerate limit to 60 fps and hides screen cursor.
    @TODO:
        Create a class Configuration with attributes related to
    screen size, fps and pixel depth. This method should call
    Configuration methods.
    */
    void windowConfig();

    /*
    @TODO: Entities data and creation should be handle by a Map class
    Each map has information about tiles and number of entities, besides
    their standard start position.
    */

    /*!
    @brief
        Currently creates a standard Player on (0,0) position
    and add it to the last node of _entity_list.
        If function fails on Entity memory allocation, throws
    an exception, that will be catched by the special handler.
    */
    void createEntity();

    /*!
    @brief
        Calls update method for each Entity on _entity_list.
    There's an assert to ensure that deltatime is positive.
    @param dt   Deltatime passed since last frame
    */
    void updateEntities( sf::Time& dt );

    /*!  
    @brief
        Calls render method for each Entity on _entity_list.
    */
    void renderEntities();

    /*!
    @brief
        Handle IO, time and window events, taking actions
    or updating Entities according with entries.
    @param Event    Event detected on gameLoop() method 
    */
    void eventHandler( sf::Event& );

    /*!
    @brief
        The game loop itself, should call all other important methods
    to update screen, entities, maps and handlers.
        Works on following order: eventHandling -> update -> render
    */
    void gameLoop();

private:
    /*! @typedef
    To help on methods update and render, at list iteration
    */ 
    typedef std::list<Entity*>::iterator iterator;

    /*! @property
    Singleton instance of AssetManager, manages every game texture
    */
    AssetManager * _manager;

    /*! @property
    A RenderWindow object reference, used to configure, draw and display */
    sf::RenderWindow * _window;

    /* TODO: Create a Clock class, add a reference here */
    sf::Time _elapsedTime;
    sf::Clock _clock;

    /*! @property 
    Temporary, list of Entity* created along the game
    @TODO:
        Create a gameMap class that contains every Entity on its
    own private attribute, according to the current game section */
    std::list<Entity*> _entities_queue;

    /*! @property
    Traits flag that allow debug */
    static const bool debugged = Traits<Game>::debugged;

    /*! @property
    Traits flag that allow tracing if debug and tracer is active */
    static const bool traced = debugged && Tracer::enable;
};
#endif