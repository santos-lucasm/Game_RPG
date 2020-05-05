#ifndef _PLAYER_H
#define _PLAYER_H

#include "creature.h"

class Player: public Creature
{
public:
    Player(std::string name, Position * pos, int hp = 100, int attack = 20, int armor = 10, int evasion = 3);
    ~Player();

    int get_hp();
    int get_attack();
    int get_armor();
    int get_evasion();

    void status();

private:
    void set_hp( int );
    void set_attack( int );
    void set_armor( int );
    void set_evasion( int );

private:
    int _hp;
    int _attack;
    int _armor;
    int _evasion;
};

#endif