#ifndef _CLICK_COMMAND_H
#define _CLICK_COMMAND_H

#include "engine/command/command.h"

class ClickCommand: public Command
{
public:
    ClickCommand();
    ~ClickCommand();
    void execute(GameObject& GameObject);
};

#endif