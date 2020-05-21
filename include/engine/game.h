#ifndef _GAME_H
#define _GAME_H

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
    /*! @brief
        Initializes the window screen and calls
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
        Currently creates a Entity of type T on a starting position
    and add it to the last node of _entityList.
        If function fails on Entity memory allocation, throws
    an exception, that will be catched by the special handler.
    @param  T   Entity inheritance class
    @param  name        Name of the object
    @param  textFile    File for the texture to be loaded
    @param  startPos    Starting position of the Entity
    @param  size        Size of the Entity, on X and Y axis
    */
    template<typename T>
    void createEntity(std::string name, std::string textFile, sf::Vector2f startPos, sf::Vector2i size);

    /*! @brief
        Calls updateSFMLEvents to check for keybinds input,
    then calls update method for each Entity on _entity_list.
    */
    void update();

    /*! @brief
        Handle IO, time and window events, taking actions
    or updating Entities according with entries.
    */
    void updateSFMLEvents();

    /*! @brief
        Updates data showed on the screen corner.
    */
    void updateDisplay();

    /*! @brief
        Calls render method for each Entity on _entityList.
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
        Initializes the current Render and data display.
    Setting font, position, color, outline, etc.
    */
    void initDisplay();

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
    Stores last event to be handle by the updateSFMLEvent method */
    sf::Event _event;

    /*! @property 
    Temporary, list of Entity* created along the game. */
    std::list<Entity*> _entitiesList;

    /*! @property 
    Data used to provide information about the game state to the user. */
    sf::Font _font;
    sf::Text _showFPS;
    std::ostringstream _fps;

    /*! @property
    Traits flag that allow debug if class debug and tracer debug are active. */
    static const bool debugged = Traits<Game>::debugged && Tracer::debugActive;

    /*! @property
    Traits flag that allow tracing if class tracing and tracer are active. */
    static const bool traced = Traits<Game>::traced && Tracer::traceActive;
};
#endif