#include "player.h"

int main()
{
    string temp;

    cout << "Welcome! What's your name ?\n\t";
    cin >> temp;

    Player * protagonist = new Player( temp );
    protagonist->status();

    return 0;
}