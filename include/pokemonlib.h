#ifndef POKEMONLIB_H
#define POKEMONLIB_H

#include <iostream>
using namespace std;

class Pokemon
{
    private:
        int _hp;
        int _mana;
        int _attack;
        int _defense;
        string _name;
        int _type;

        void setName( string n ) { _name = n; }
        void setType( int a ){ _type = a; }

    public:
        Pokemon(int, int, int, int, string, int);
        ~Pokemon();

        //SET METHODS
        void setHP( int h ) { _hp = h; }
        void setMana( int m ) { _mana = m; }
        void setAttack( int a ) { _attack = a; }
        void setDefense( int a ) { _defense = a; }  

        string printType( int );
        enum Type {
            Grass,
            Fire,
            Water
        }; 

    public:
        //GET METHODS
        int getHP() { return _hp; }
        int getMana() { return _mana; }
        int getAttack() { return _attack; }
        int getDefense() { return _defense; }
        string getName() { return _name; }
        int getType() { return _type; } 

        //VIRTUAL OPERATIONS
        virtual void attack(Pokemon*) = 0;
        //virtual void ultimate() = 0;
        virtual void print() = 0;
};

Pokemon::Pokemon(int hp, int mana, int attack, int defense, string name, int type)
{   
    setHP( hp );
    setMana( mana );
    setAttack( attack );
    setDefense( defense );
    setName( name );
    setType( type );
}

Pokemon::~Pokemon()
{
    setHP(0);
    setMana(0);
    setAttack(0);
    setDefense(0);
    setName(nullptr);
}

string Pokemon::printType(int type)
{
    switch (type)
    {
    case 0:
        return "Grass"; break;
    case 1:
        return "Fire"; break;
    case 2:
        return "Water"; break;
    default:
        return nullptr; break;
    }
}
#endif