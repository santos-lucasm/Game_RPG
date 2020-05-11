#ifndef _GAME_H
#define _GAME_H

#include "Entities/player.h"
#include "Manager/asset_manager.h"
#include "location.h"

#include <list>

class Game
{
public:
    Game( std::string );
    ~Game();

    void windowConfig();

    void createEntity();
    void updateEntities( sf::Time& dt );
    void renderEntities();

    void eventHandler( sf::Event& );
    void gameLoop();

private:
    AssetManager * _manager;
    sf::RenderWindow * _window;

    /* TODO: Add a Clock class, add a reference here */
    sf::Time _elapsedTime;
    sf::Clock _clock;

    /* Temporary */
    std::list<Entity*> _entities_queue;

    /* Traits flag that allow debug */
    static const bool debugged = Traits<Game>::debugged;
    /* Traits flag that allow tracing if debug and tracer is active */
    static const bool traced = debugged && Tracer::enable;
};
#endif