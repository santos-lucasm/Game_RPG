#ifndef _MOVE_COMMAND_H
#define _MOVE_COMMAND_H

#include "engine/command/command.h"

class MoveRightCommand: public Command
{
public:
    MoveRightCommand(){}
    ~MoveRightCommand(){}
    void execute(GameObject& gameObject);
};

class MoveLeftCommand: public Command
{
public:
    MoveLeftCommand(){}
    ~MoveLeftCommand(){}
    void execute(GameObject& gameObject);
};

class MoveUpCommand: public Command
{
public:
    MoveUpCommand(){}
    ~MoveUpCommand(){}
    void execute(GameObject& gameObject);
};

class MoveDownCommand: public Command
{
public:
    MoveDownCommand(){}
    ~MoveDownCommand(){}
    void execute(GameObject& gameObject);
};

#endif