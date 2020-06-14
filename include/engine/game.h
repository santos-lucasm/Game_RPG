#ifndef _GAME_H
#define _GAME_H

#include "engine/machine_state.h"
#include "state/main_menu_state.h"

#include "middleware/event_manager.h"
#include "clock.h"

class Game
{
public:
    Game();
    ~Game();

    void update();
    void render();
    void gameLoop();
private:
    void initWindow();

    sf::RenderWindow* _window;
    Clock* _clock;

    Machine* _fsm;
    AssetManager* m_Asset;
    EventManager* m_Event;
};
#endif