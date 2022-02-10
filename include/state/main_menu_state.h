#ifndef _MAIN_MENU_STATE_H
#define _MAIN_MENU_STATE_H

#include "state/run_state.h"

class MainMenuState: public GameState
{
public:
    MainMenuState(sf::RenderWindow* window);
    ~MainMenuState();

    void update(sf::Time& dt);
    void render(sf::RenderTarget* target = nullptr);
    void goNext(Machine& fsm);

private:
    void initBackground();
    void initButtons();

    sf::RectangleShape _background;
    /*
    Button* _playButton;
    Button* _settingsButton;
    Button* _saveButton;
    */
};

#endif