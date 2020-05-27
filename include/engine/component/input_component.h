#ifndef _INPUT_COMPONENT_H
#define _INPUT_COMPONENT_H

#include "engine/command/input_handler.h"

class InputComponent
{
public:
    InputComponent();
    ~InputComponent();
    void update(Entity& entity);

private:
    InputHandler* _inputHandler;
};

#endif