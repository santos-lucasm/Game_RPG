#ifndef _MOVE_COMMAND_H
#define _MOVE_COMMAND_H

#include "engine/command/command.h"

class MoveRightCommand: public Command
{
public:
    MoveRightCommand(){}
    ~MoveRightCommand(){}
    void execute(Entity& entity);
};

class MoveLeftCommand: public Command
{
public:
    MoveLeftCommand(){}
    ~MoveLeftCommand(){}
    void execute(Entity& entity);
};

class MoveUpCommand: public Command
{
public:
    MoveUpCommand(){}
    ~MoveUpCommand(){}
    void execute(Entity& entity);
};

class MoveDownCommand: public Command
{
public:
    MoveDownCommand(){}
    ~MoveDownCommand(){}
    void execute(Entity& entity);
};

#endif