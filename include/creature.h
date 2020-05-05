#ifndef _CREATURE_H
#define _CREATURE_H

#include "types.h"

/*
TODO: This'll be an abstract class.
Every class that inherits it will have to implement a walk method.
*/

class Creature
{
public:
    Creature( std::string, Position * );
    ~Creature();

    std::string get_name();
    Position * get_position();

protected:
    void set_name( std::string );
    void set_position( Position * );

private:
    std::string _name;
    Position * _pos;
};

#endif