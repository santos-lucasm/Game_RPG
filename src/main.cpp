#include "game.h"

int main()
{
    Game * newGame = new Game();

    newGame->createEntity<Player>("Player1", "resources/animations/snorlax.png", sf::Vector2f(200,200));
    newGame->gameLoop();

    delete newGame;
    return 0;
}