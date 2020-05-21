#include "engine/game.h"

int main()
{
    Game * newGame = new Game();

    newGame->createEntity<Player>("Player1", ANIMATION_PATH(snorlax), sf::Vector2f(200,200), sf::Vector2i(32, 32));
    newGame->gameLoop();

    delete newGame;
    return 0;
}