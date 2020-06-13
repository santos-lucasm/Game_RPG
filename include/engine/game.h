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
    AssetManager* m_Asset;
    EventManager* m_Event;
    Clock* _clock;
    sf::Event _event;
};
#endif