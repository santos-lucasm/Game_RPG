#include "engine/command/move_command.h"

void MoveRightCommand::execute(GameObject& gameObject)
{
    gameObject._velocity = sf::Vector2f(1, 0);
}

void MoveLeftCommand::execute(GameObject& gameObject)
{
    gameObject._velocity = sf::Vector2f(-1, 0);
}

void MoveUpCommand::execute(GameObject& gameObject)
{
    gameObject._velocity = sf::Vector2f(0, -1);
}

void MoveDownCommand::execute(GameObject& gameObject)
{
    gameObject._velocity = sf::Vector2f(0, 1);
}