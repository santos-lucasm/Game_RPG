#include "engine/game.h"
  
int main()
{
    Game * newGame = new Game();

    newGame->gameLoop();

    delete newGame;
    return 0;
}