#ifndef _COMMAND_H
#define _COMMAND_H

#include "entities/player.h"
class Command
{
public:
    Command(){}
    virtual ~Command(){}
    virtual void execute(GameObject& GameObject) = 0;
};

#endif