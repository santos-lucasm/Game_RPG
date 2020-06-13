#ifndef _PLAYER_INPUT_H
#define _PLAYER_INPUT_H

#include "entities/player.h"

class PlayerInputComponent: public InputComponent
{
public:
    PlayerInputComponent();
    ~PlayerInputComponent();
    void update(GameObject& gameObject);

    void handleInput(GameObject& gameObject);
private:
    
    void initButtons();
};

#endif