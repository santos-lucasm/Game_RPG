#ifndef _COMMAND_H
#define _COMMAND_H

#include "entities/game_object.h"
class Command
{
public:
    Command(){}
    virtual ~Command(){}
    virtual void execute(GameObject& gameObject) = 0;
};

#endif