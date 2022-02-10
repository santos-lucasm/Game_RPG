#ifndef _PLAYER_INPUT_H
#define _PLAYER_INPUT_H

#include "entities/player.h"

class PlayerInputComponent: public InputComponent
{
public:
    PlayerInputComponent();
    ~PlayerInputComponent();
    void update(GameObject& obj);

    void handleInput(GameObject& obj);
private:
    
    void initButtons();
};

#endif