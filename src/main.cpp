#include "game.h"

int main()
{
    Game * newGame = new Game("Titlezinho");

    newGame->windowConfig();
    newGame->createEntity<Player>();
    newGame->gameLoop();

    delete newGame;
    return 0;
}