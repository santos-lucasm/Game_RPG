#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;

class Player
{
public:
    Player(string name, int hp = 100, int attack = 20, int armor = 10, int evasion = 3);
    ~Player();

    void set_name( string );
    void set_hp( int );
    void set_attack( int );
    void set_armor( int );
    void set_evasion( int );

    string get_name();
    int get_hp();
    int get_attack();
    int get_armor();
    int get_evasion();

    void status();

private:
    string _name;
    int _hp;
    int _attack;
    int _armor;
    int _evasion;
};

#endif