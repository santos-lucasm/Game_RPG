#include "../include/pokemons/cyndaquil.h"

int main()
{

    Pokemon* Poke1 = new Cyndaquil();
    Pokemon* Poke2 = new Cyndaquil();

    Poke1->print();
    Poke2->attack(Poke1);
    Poke1->print();

    return 0;
}