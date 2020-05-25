#ifndef _MOVE_COMMAND_H
#define _MOVE_COMMAND_H

#include "engine/commands/command.h"

class MoveRightCommand: public Command
{
public:
    MoveRightCommand(){}
    ~MoveRightCommand(){}
    void execute(Player& entity, float& dt);
};

class MoveLeftCommand: public Command
{
public:
    MoveLeftCommand(){}
    ~MoveLeftCommand(){}
    void execute(Player& entity, float& dt);
};

class MoveUpCommand: public Command
{
public:
    MoveUpCommand(){}
    ~MoveUpCommand(){}
    void execute(Player& entity, float& dt);
};

class MoveDownCommand: public Command
{
public:
    MoveDownCommand(){}
    ~MoveDownCommand(){}
    void execute(Player& entity, float& dt);
};

#endif