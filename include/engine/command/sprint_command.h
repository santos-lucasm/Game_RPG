#ifndef _SPRINT_COMMAND_H
#define _SPRINT_COMMAND_H

#include "engine/command/command.h"

class SprintCommand: public Command
{
public:
    SprintCommand(unsigned int id);
    ~SprintCommand();
    void execute(GameObject& gameObject);
};

#endif