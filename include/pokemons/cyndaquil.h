#ifndef CYNDAQUIL_H
#define CYNDAQUIL_H

#include "../pokemonlib.h"

class Cyndaquil: public Pokemon
{
    public:
        Cyndaquil(int hp = 39, int mana = 100, int attack = 52, int defense = 43):
            Pokemon(hp, mana, attack, defense, "Cyndaquil", Pokemon::Type::Fire) {}

        void attack( Pokemon * );
        //void ultimate();
        void print();
     
};

void Cyndaquil::attack( Pokemon * target )
{   
    int damage = getAttack() - target->getDefense();
    cout << getName() << " attacked causing " << damage << " points of damage!" << endl;
    target->setHP( getHP() - damage );
}

void Cyndaquil::print()
{
    cout << "NAME: " << getName() << endl;
    cout << "TYPE: " << printType( getType() ) << endl;

    cout << "STATS: "<< endl;
    cout << "----------" << "\t" << "-------------" << endl;
    cout << "| HP: "<< getHP() << " |" << "\t" << "| Mana: "<< getMana() << " |" << endl;
    cout << "----------" << "\t" << "-------------" << endl;

    cout << "\tAttack: " << getAttack() << "\n\tDefense: " << getDefense() << endl;
}
#endif