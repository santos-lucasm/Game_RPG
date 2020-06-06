#ifndef _GAME_H
#define _GAME_H

#include "engine/machine_state.h"
#include "state/main_menu_state.h"

#include "engine/event/subject.h"
#include "clock.h"

class Game: public Subject
{
public:
    Game();
    ~Game();

    void update();
    void updateSFMLEvents();
    void notify();

    void render();
    void gameLoop();
private:
    void initWindow();

    sf::RenderWindow* _window;

    Machine* _fsm;
    AssetManager* _manager;
    Clock* _clock;
    sf::Event _event;

    static const bool debugged = Traits<Game>::debugged && Tracer::debugActive;
    static const bool traced = Traits<Game>::traced && Tracer::traceActive;
};
#endif