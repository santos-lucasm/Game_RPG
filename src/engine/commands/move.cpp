#include "engine/commands/move.h"

void MoveRightCommand::execute(Player& entity, float& dt)
{
    entity.move( entity.getSpeed()*dt, 0, RIGHT_MOVE, "walk-right");
}

void MoveLeftCommand::execute(Player& entity, float& dt)
{
    entity.move( -entity.getSpeed()*dt, 0, LEFT_MOVE, "walk-left");
}

void MoveUpCommand::execute(Player& entity, float& dt)
{
    entity.move( 0, -entity.getSpeed()*dt, UP_MOVE, "walk-up");
}

void MoveDownCommand::execute(Player& entity, float& dt)
{
    entity.move( 0, entity.getSpeed()*dt, DOWN_MOVE, "walk-down");
}