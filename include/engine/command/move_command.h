#ifndef _MOVE_COMMAND_H
#define _MOVE_COMMAND_H

#include "engine/command/command.h"

class MoveRightCommand: public Command
{
public:
    MoveRightCommand(unsigned int id): Command(id) {}
    ~MoveRightCommand(){}
    void execute(GameObject& gameObject);
};

class MoveLeftCommand: public Command
{
public:
    MoveLeftCommand(unsigned int id): Command(id) {}
    ~MoveLeftCommand(){}
    void execute(GameObject& gameObject);
};

class MoveUpCommand: public Command
{
public:
    MoveUpCommand(unsigned int id): Command(id) {}
    ~MoveUpCommand(){}
    void execute(GameObject& gameObject);
};

class MoveDownCommand: public Command
{
public:
    MoveDownCommand(unsigned int id): Command(id) {}
    ~MoveDownCommand(){}
    void execute(GameObject& gameObject);
};

#endif