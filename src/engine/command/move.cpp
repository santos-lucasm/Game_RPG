#include "engine/command/move.h"

void MoveRightCommand::execute(Entity& entity)
{
    entity._velocity = sf::Vector2f(1, 0);
}

void MoveLeftCommand::execute(Entity& entity)
{
    entity._velocity = sf::Vector2f(-1, 0);
}

void MoveUpCommand::execute(Entity& entity)
{
    entity._velocity = sf::Vector2f(0, -1);
}

void MoveDownCommand::execute(Entity& entity)
{
    entity._velocity = sf::Vector2f(0, 1);
}