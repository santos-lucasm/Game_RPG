#ifndef _PLAYER_INPUT_H
#define _PLAYER_INPUT_H

#include "entities/player.h"
#include "engine/command/move_command.h"
#include "engine/command/sprint_command.h"

class PlayerInputComponent: public InputComponent
{
public:
    PlayerInputComponent();
    ~PlayerInputComponent();
    void update(GameObject& gameObject);

    void handleInput(GameObject& gameObject);
private:
    
    void initButtons();
    /*
    Command* _buttonRight;
    Command* _buttonLeft;
    Command* _buttonUp;
    Command* _buttonDown;
    Command* _buttonSprint;
    */

    static const bool debugged = Traits<PlayerInputComponent>::debugged && Tracer::debugActive;
    static const bool traced = Traits<PlayerInputComponent>::traced && Tracer::traceActive;
};

#endif