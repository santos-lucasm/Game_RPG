#ifndef _COMMAND_H
#define _COMMAND_H

// class Entity;
#include "entities/entity.h"
class Command
{
public:
    Command(){}
    virtual ~Command(){}
    virtual void execute(Entity& entity) = 0;
};

#endif