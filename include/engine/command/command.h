#ifndef _COMMAND_H
#define _COMMAND_H

#include "entities/game_object.h"
class Command
{
public:
    Command(unsigned int id): _id(id) {}
    virtual ~Command(){}

    virtual void execute(GameObject& gameObject) = 0;
    unsigned int getID() const { return _id; }
protected:
    unsigned int _id;
};

#endif