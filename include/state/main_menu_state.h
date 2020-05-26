#ifndef _MAIN_MENU_STATE_H
#define _MAIN_MENU_STATE_H

#include "state/state.h"
#include "entities/button.h"

class MainMenuState: public State
{
public:
    MainMenuState(sf::RenderWindow* window);
    ~MainMenuState();

    void update(sf::Time& dt);
    void render(sf::RenderTarget* target = nullptr);

private:
    void initButtons();

    sf::RectangleShape _background;
    Button* _playButton;
    Button* _settingsButton;
    Button* _saveButton;

    static const bool debugged = Traits<MainMenuState>::debugged && Tracer::debugActive;
    static const bool traced = Traits<MainMenuState>::traced && Tracer::traceActive;
};

#endif