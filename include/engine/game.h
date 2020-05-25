#ifndef _GAME_H
#define _GAME_H

#include "state/game_state.h"
#include "state/main_menu_state.h"

#include "clock.h"

class Game
{
public:
    Game();
    ~Game();

    void update();
    void updateSFMLEvents();

    void render();
    void gameLoop();
private:
    void initWindow();
    void initState();

    sf::RenderWindow* _window;
    std::stack<State*> _states;

    AssetManager* _manager;
    Clock* _clock;
    sf::Event _event;

    static const bool debugged = Traits<Game>::debugged && Tracer::debugActive;
    static const bool traced = Traits<Game>::traced && Tracer::traceActive;
};
#endif