#ifndef _GAME_H
#define _GAME_H

#include <list>

#include "entities/player.h"
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
    /*!
    @brief
        Gets current screen configuration utilized by user
    and uses it to create a new window.
    */
    Game();

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
    void initWindow();

    /*
    @TODO: Entities data and creation should be handle by a Map class
    Each map has information about tiles and number of entities, besides
    their standard start position.
    */

    /*!
    @brief
        Currently creates a Entity of type T on (0,0) position
    and add it to the last node of _entity_list.
        If function fails on Entity memory allocation, throws
    an exception, that will be catched by the special handler.
    */
    template<typename T>
    void createEntity(std::string, std::string, sf::Vector2f);

    /*!
    @brief
        Calls update method for each Entity on _entity_list.
    There's an assert to ensure that deltatime is positive.
    @param Time Deltatime passed since last frame.
    */
    void updateEntities( sf::Time& );

    /*!  
    @brief
        Calls render method for each Entity on _entity_list.
    */
    void render();

    /*!
    @brief
        Handle IO, time and window events, taking actions
    or updating Entities according with entries.
    */
    void eventHandler();

    /*!
    @brief
        The game loop itself, should call all other important methods
    to update screen, entities, maps and handlers.
        Works on following order: eventHandling -> update -> render.
    */
    void gameLoop();

private:
    /*! @typedef
    To help on methods update and render, at list iteration. */ 
    typedef std::list<Entity*>::iterator iterator;

    /*! @property
    Singleton instance of AssetManager, manages every game texture. */
    AssetManager * _manager;

    /*! @property
    A RenderWindow object reference, used to configure, draw and display. */
    sf::RenderWindow * _window;

    /*! @property
    Clock class will store data about the frame and game duration. */
    Clock * _clock;

    /*! @property
    Stores last event to be handle by the eventHandler method */
    sf::Event _event;

    /*! @property 
    Temporary, list of Entity* created along the game.
    @TODO:
        Create a gameMap class that contains every Entity on its
    own private attribute, according to the current game section */
    std::list<Entity*> _entities_queue;

    /*! @property
    Traits flag that allow debug if class debug and tracer debug are active. */
    static const bool debugged = Traits<Game>::debugged && Tracer::debugActive;

    /*! @property
    Traits flag that allow tracing if class tracing and tracer are active. */
    static const bool traced = Traits<Game>::traced && Tracer::traceActive;
};
#endif