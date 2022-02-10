#ifndef _SETTINGS_STATE_H
#define _SETTINGS_STATE_H

#include "engine/machine_state.h"
#include "state/game_state.h"

class SettingsMenuState: public GameState
{
public:
    SettingsMenuState(sf::RenderWindow* window);
    ~SettingsMenuState();
    
    void update(sf::Time& dt);
    void render(sf::RenderTarget* target = nullptr);
    void goNext(Machine& fsm);

    void updateFPS(sf::Time& dt);
private:
    void initFPS();

    sf::Font _font;
    sf::Text _showFPS;
    std::ostringstream _fps;
};

#endif