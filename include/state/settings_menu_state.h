#ifndef _SETTINGS_STATE_H
#define _SETTINGS_STATE_H

#include "state/main_menu_state.h"

class SettingsMenuState: public State
{
public:
    SettingsMenuState(sf::RenderWindow* window);
    ~SettingsMenuState();
    
    void update(sf::Time& dt);
    void updateInput();
    void updateFPS(sf::Time& dt);
    void render(sf::RenderTarget* target = nullptr);

private:
    void initWindow();
    void initFPS();

    sf::Font _font;
    sf::Text _showFPS;
    std::ostringstream _fps;

    static const bool debugged = Traits<SettingsMenuState>::debugged && Tracer::debugActive;
    static const bool traced = Traits<SettingsMenuState>::traced && Tracer::traceActive;
};

#endif