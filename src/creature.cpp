#include "creature.h"
using namespace std;

Creature::Creature( string name, Position * pos)
{
    set_name( name );
    set_position( pos );
}

Creature::~Creature()
{
    set_name(nullptr);
    set_position(nullptr);
}

void Creature::set_name( string name ){ _name = name; }
void Creature::set_position( Position * pos) { _pos = pos; }

string Creature::get_name(){ return _name; }
Position * Creature::get_position() { return _pos; }