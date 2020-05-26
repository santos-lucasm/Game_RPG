#ifndef _SETTINGS_STATE_H
#define _SETTINGS_STATE_H

#include "state/state.h"

class SettingsMenuState: public State
{
public:
    SettingsMenuState(sf::RenderWindow* window, std::stack<State*>* states);
    ~SettingsMenuState();
    
    void update(sf::Time& dt);
    void updateFPS(sf::Time& dt);
    void render(sf::RenderTarget* target = nullptr);
    void onNotify(sf::Event& event);
private:
    void initFPS();

    sf::Font _font;
    sf::Text _showFPS;
    std::ostringstream _fps;

    static const bool debugged = Traits<SettingsMenuState>::debugged && Tracer::debugActive;
    static const bool traced = Traits<SettingsMenuState>::traced && Tracer::traceActive;
};

#endif