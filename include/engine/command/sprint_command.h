#ifndef _SPRINT_COMMAND_H
#define _SPRINT_COMMAND_H

#include "engine/command/command.h"

class SprintCommand: public Command
{
public:
    SprintCommand();
    ~SprintCommand();
    void execute(GameObject& gameObject);
};

#endif