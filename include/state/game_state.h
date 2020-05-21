#ifndef _GAME_STATE_H
#define _GAME_STATE_H

#include "state/settings_state.h"

class GameState: public State
{
public:
    GameState(sf::RenderWindow* window);
    ~GameState();

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
    void render(sf::RenderTarget *target = nullptr);

    /*! @brief
        Currently creates a Entity of type T on a starting position
    and add it to the last node of _entityList.
        If function fails on Entity memory allocation, throws
    an exception, that will be catched by the special handler.
    @param  T           Entity inheritance class
    @param  name        Name of the object
    @param  textFile    File for the texture to be loaded
    @param  startPos    Starting position of the Entity
    @param  size        Size of the Entity, on X and Y axis
    */
    template<typename T>
    void createEntity(std::string name, std::string textFile, sf::Vector2f startPos, sf::Vector2i size);

private:
    /*! @property 
    Temporary, list of Entity* created along the game. */
    std::list<Entity*> _entitiesList;

    SettingsState* _settings;

    /*! @property
    Traits flag that allow debug if class debug and tracer debug are active. */
    static const bool debugged = Traits<Game>::debugged && Tracer::debugActive;

    /*! @property
    Traits flag that allow tracing if class tracing and tracer are active. */
    static const bool traced = Traits<Game>::traced && Tracer::traceActive;
};

#endif